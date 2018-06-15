#include "databaseutils.h"
#include "dialogtransfer.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlQuery>

#include <QDebug>
#include "common_const.h"


#define DEBUG_PRE "DialogTransfer"
DialogTransfer::DialogTransfer(QString ocd, QString subaccount)
{
    if(!ctrl.set_onecard(ocd)){
        QMessageBox::warning(this,tr("Error"),tr("One Card ID ERROR"));
    }
    this->saccount=subaccount;
    this->ocd=ocd;

    init_res();
    init_ui();
    init_data();

    connect(cb_name,&QComboBox::currentTextChanged,this,&DialogTransfer::slots_name_changed);
    connect(cb_onecard,&QComboBox::currentTextChanged,this,&DialogTransfer::slots_onecard_changed);
    connect(btn_cancel,&QPushButton::clicked,this,[this](){this->reject();});
    connect(btn_accept,&QPushButton::clicked,this,&DialogTransfer::slots_transfer_money);


}

void DialogTransfer::init_res()
{
    layout_fl=new QFormLayout;
    cb_name=new QComboBox;
    cb_onecard=new QComboBox;
    le_count=new QLineEdit;
    btn_accept=new QPushButton(tr("Accept"));
    btn_cancel=new QPushButton(tr("Cancel"));


    new_name=false;



}

void DialogTransfer::init_ui()
{
    this->setLayout(layout_fl);

    layout_fl->addRow(tr("Name:"),cb_name);
    layout_fl->addRow(tr("Account:"),cb_onecard);
    layout_fl->addRow(tr("Count"),le_count);
    layout_fl->addRow(btn_accept,btn_cancel);

    cb_name->setEditable(true);
    cb_onecard->setEditable(true);


}

void DialogTransfer::init_data()
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<db.lastError();
    }
    QSqlQuery query(db);
    QString tmp="SELECT idcard FROM one_card WHERE id='%1'";
    if(!query.exec(tmp.arg(ctrl.get_onecard()))){
        qDebug()<<DEBUG_PRE<<query.lastError();
        return ;
    }
    query.next();
    idcard=query.value(0).toString();
    tmp="SELECT name,onecard FROM familiar WHERE idcard='%1' ";
    if(!query.exec(tmp.arg(idcard))){
        qDebug()<<DEBUG_PRE<<query.lastError();
        return ;
    }
    while(query.next()){
        map.insert(query.value(0).toString(),query.value(1).toString());
    }
    cb_name->addItems(map.keys());
    cb_onecard->addItems(map.values(cb_name->currentText()));



}

QPair<bool, QString> DialogTransfer::store_familiar(QString name, QString ocd)
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        return {false,db.lastError().text()};
    }
    QString tmp="INSERT INTO familiar(onecard,name,idcard) VALUES('%1','%2','%3')";
    QSqlQuery query(db);
    if(!query.exec(tmp.arg(ocd).arg(name).arg(idcard))){
        return {false,query.lastError().text()};
    }
    map.insert(name,ocd);
    return {true,"Success"};

}

void DialogTransfer::slots_name_changed(QString name)
{
    if(!map.contains(name)){
        new_name=true;
        cb_onecard->clear();

        return ;
    }else{
    cb_onecard->addItems(map.values(cb_name->currentText()));
    new_name=false;
    }

}

void DialogTransfer::slots_onecard_changed(QString ocd)
{
//    if(new_name){

    if(-1==cb_onecard->findText(ocd)){
        return;
    }
        map.insert(cb_name->currentText(),ocd);
        auto ret=store_familiar(cb_name->currentText(),ocd);
        if(!ret.first){
            QMessageBox::warning(this,tr("Error"),tr("Store Familiar Failed:")+ret.second);
        }


//    }else{
//    }

}

void DialogTransfer::slots_transfer_money()
{
    auto ret=ctrl.withdraw(saccount.toInt(),le_count->text().toInt(),{"Transfer","Transfer to "+cb_name->currentText()+cb_onecard->currentText()});
    if(!ret.first){
        QMessageBox::warning(this,tr("Error"),ret.second);
        return ;
    }
    ctrl.set_onecard(cb_onecard->currentText());
    ret=ctrl.deposit(saccount.left(1).toInt(),saccount.left(2).right(1).toInt(),le_count->text().toInt(),0,0,false,"Recever From "+this->idcard);
    ctrl.set_onecard(ocd);
    if(!ret.first){
        QMessageBox::warning(this,tr("Error"),ret.second);
        return;
    }
    QMessageBox::information(this,tr("Success"),tr("Fransfer Successed"));
    this->accept();

}
