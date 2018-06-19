#include "dialogrecord.h"
#include "dialogtransfer.h"
#include "widgetonlinebank.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QModelIndexList>
#include <QMessageBox>
#include <QInputDialog>

#include "dialoganaly.h"
#include "dialogpaycreditcard.h"
#include "dialogpeople.h"
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define DEBUG_PRE __FILE__ "WidgetOnlineBank:" TOSTRING(__LINE__)

static QString str_query="SELECT id,s_type,benjin,nianxian,lilv,qishi_shijian,ac,lixi FROM saving_subaccount WHERE cid='%1' ";

WidgetOnlineBank::WidgetOnlineBank(online_ctrl &c, QWidget *parent) :QWidget(parent),ctrl(c)
{

    init_res();
    init_ui();
    init_data();

    connect(btn_analy,&QPushButton::clicked,this,&WidgetOnlineBank::show_analy);
    connect(btn_record,&QPushButton::clicked,this,&WidgetOnlineBank::show_record);
    connect(btn_transfer,&QPushButton::clicked,this,&WidgetOnlineBank::slots_transfer);
    connect(btn_loss_report,&QPushButton::clicked,this,&WidgetOnlineBank::slots_loss_report);
    connect(btn_people,&QPushButton::clicked,this,&WidgetOnlineBank::slots_people);
    connect(cb_onecard,&QComboBox::currentTextChanged,this,[this](QString str){
        sqlmodel->setQuery(str_query.arg(str),DataBaseUtils::getInstance());
    });
    connect(btn_open_creditcard,&QPushButton::clicked,this,&WidgetOnlineBank::slots_open_creditcard);
    connect(btn_pay_creditcard,&QPushButton::clicked,this,&WidgetOnlineBank::slots_pay_creditcard);
}

void WidgetOnlineBank::show_record()
{
    DialogRecord dia(ctrl.get_idcard());
    if(dia.exec()==QDialog::Accepted){
        qDebug()<<DEBUG_PRE<<"Accept";
        return ;
    }
        qDebug()<<DEBUG_PRE<<"Reject";
        return;



}

void WidgetOnlineBank::slots_transfer()
{
    auto m=tv_lview->selectionModel();
    auto row=m->selectedRows();
    
    if(row.size()==0||row.at(0).data().toString().at(1)!="1"){
        QMessageBox::warning(this,tr("Error"),tr("You Should Select a Current subaccount"));
        return ;
    }
    DialogTransfer dia(cb_onecard->currentText(),row.at(0).data().toString());
    if(dia.exec()==QDialog::Accepted){
        qDebug()<<DEBUG_PRE<<"Transfer Successed";
    }else{
        qDebug()<<DEBUG_PRE<<"Transfer Failed";
    }
    sqlmodel->setQuery(str_query.arg(cb_onecard->currentText()),DataBaseUtils::getInstance());
    
    


        
    

}

void WidgetOnlineBank::show_analy()
{
    DialogAnaly	dia(ctrl.get_idcard());
    if(dia.exec()==QDialog::Accepted){
        qDebug()<<DEBUG_PRE<<"analy accepted";
    }else{
        qDebug()<<DEBUG_PRE<<"analy rejected";

    }

}

void WidgetOnlineBank::slots_loss_report()
{
    //TODO xijie
    one_card_account account(this->cb_onecard->currentText());
    account.set_loss(true);
    QMessageBox::information(this,tr("Success"),tr(
                                 "Loss Report Successed"));

}

void WidgetOnlineBank::slots_people()
{
    DIalogPeople dia(ctrl.get_idcard());
    if(dia.exec()==QDialog::Accepted){
        qDebug()<<DEBUG_PRE<<"ACCEPTED";
        return ;
    }
        qDebug()<<DEBUG_PRE<<"REJECTED";

}

void WidgetOnlineBank::slots_open_creditcard()
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<db.lastError();
        return ;
    }
    QSqlQuery query(db);

    QString passwd=QInputDialog::getText(this,tr("Please Input"),tr("Please Input Passwd"));
    if(passwd.isEmpty()){
        return ;
    }
    QString tmp="INSERT INTO credit_card(credit,passwd,cid,interest_free_money) VALUES('%1','%2','%3','%4')";
    auto va=qrand()%10000;
    if(!query.exec(tmp.arg(va).arg(passwd).arg(ctrl.get_idcard()).arg(va))){
        qDebug()<<DEBUG_PRE<<query.lastError();
        return;
    }
    QMessageBox::information(this,tr("Success"),tr("You Have Open Credit Card"));
}

void WidgetOnlineBank::slots_pay_creditcard()
{
    auto model=tv_lview->selectionModel();
    auto row=model->selectedRows();
    if(row.count()==0){
        QMessageBox::warning(this,tr("Error"),tr("You Shoule select a current deposit"));
        return ;
    }
    DialogPayCreditCard dia(ctrl.get_idcard(),row.at(0).data().toString(),cb_onecard->currentText());
    if(dia.exec()==QDialog::Accepted){
        qDebug()<<DEBUG_PRE<<"accept";
    }else{
        qDebug()<<DEBUG_PRE<<"REJECT";
    }

}

void WidgetOnlineBank::init_res()
{

    layout_main=new QHBoxLayout;
    layout_rv=new QVBoxLayout;
    layout_lv=new QVBoxLayout;

    tv_lview=new QTableView;
    cb_onecard=new QComboBox;

    btn_analy=new QPushButton(tr("Analysis"));
//    btn_change_passwd=new QPushButton(tr("Change Passwd"));
    btn_loss_report=new QPushButton(tr("Loss Report"));
    btn_record=new QPushButton(tr("Recode"));
    btn_transfer=new QPushButton(tr("Transfer"));
    btn_people=new QPushButton(tr("People Manage"));
    btn_open_creditcard=new QPushButton(tr("Open Credit Card"));
    btn_pay_creditcard=new QPushButton(tr("Pay Credit Card"));

    sqlmodel=new QSqlQueryModel;

}

void WidgetOnlineBank::init_ui()
{
    this->setLayout(layout_main);

    layout_main->addLayout(layout_lv);
    layout_main->addLayout(layout_rv);

    layout_lv->addWidget(cb_onecard);
    layout_lv->addWidget(tv_lview);

    layout_rv->addWidget(btn_analy);
//    layout_rv->addWidget(btn_change_passwd);
    layout_rv->addWidget(btn_loss_report);
    layout_rv->addWidget(btn_record);
    layout_rv->addWidget(btn_transfer);
    layout_rv->addWidget(btn_people);
    layout_rv->addWidget(btn_open_creditcard);
    layout_rv->addWidget(btn_pay_creditcard);

}

void WidgetOnlineBank::init_data()
{

    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<db.lastError();
        return ;
    }
    QSqlQuery query(db);

    //ComBox
    QString tmp="SELECT id FROM one_card WHERE idcard='%1'";
    if(!query.exec(tmp.arg(ctrl.get_idcard()))){
        qDebug()<<DEBUG_PRE<<db.lastError();
        return ;
    }
    QStringList list;
    while(query.next()){
        list.append(QString::number(query.value(0).toInt()));
    }
    cb_onecard->addItems(list);

    sqlmodel=new QSqlQueryModel(this);
    sqlmodel->setQuery(str_query.arg(cb_onecard->currentText()),DataBaseUtils::getInstance());
    sqlmodel->setHeaderData(0,Qt::Horizontal,tr("ID"));
    sqlmodel->setHeaderData(1,Qt::Horizontal,tr("type"));
    sqlmodel->setHeaderData(2,Qt::Horizontal,tr("benjin"));
    sqlmodel->setHeaderData(3,Qt::Horizontal,tr("nianxian"));
    sqlmodel->setHeaderData(4,Qt::Horizontal,tr("lilv"));
    sqlmodel->setHeaderData(5,Qt::Horizontal,tr("qishi_shijian"));
    sqlmodel->setHeaderData(6,Qt::Horizontal,tr("auto continue"));
    sqlmodel->setHeaderData(7,Qt::Horizontal,tr("lixi"));


    tv_lview->setModel(sqlmodel);
    tv_lview->setSelectionMode(QAbstractItemView::SingleSelection);
    tv_lview->setSelectionBehavior(QAbstractItemView::SelectRows);

}
