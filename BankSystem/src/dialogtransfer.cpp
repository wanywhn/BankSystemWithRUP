#include "databaseutils.h"
#include "dialogtransfer.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QSqlQuery>

#include <QDebug>


#define DEBUG_PRE "DialogTransfer"
DialogTransfer::DialogTransfer(QString ocd)
{
    if(!ctrl.set_onecard(ocd)){
        QMessageBox::warning(this,tr("Error"),tr("One Card ID ERROR"));
    }
    init_res();
    init_ui();
    init_data();

    connect(cb_name,&QComboBox::currentTextChanged,this,&DialogTransfer::slots_name_changed);
    connect(cb_onecard,&QComboBox::currentTextChanged,this,&DialogTransfer::slots_onecard_changed);


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
    QString idcard=query.value(0).toString();
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

void DialogTransfer::slots_name_changed(QString name)
{
    if(!map.contains(name)){
        new_name=true;

        return ;
    }else{
    cb_onecard->addItems(map.values(cb_name->currentText()));
    }

}

void DialogTransfer::slots_onecard_changed(QString ocd)
{
    if(new_name){

    }else{

    }

}
