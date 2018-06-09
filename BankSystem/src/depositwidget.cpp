#include "databaseutils.h"
#include "depositwidget.h"
#include "dialogadddeposit.h"

#include <QHBoxLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDebug>

#define DEBUG_PRE "DepositWidget:"
DepositWidget::DepositWidget(one_card_control &ctrl, QWidget *parent):ctrl(ctrl)
{
    init_res();
    init_ui();
}

void DepositWidget::init_ui()
{


   auto hbox=new QHBoxLayout();

   hbox->addWidget(sqlView);

   auto vbox=new QVBoxLayout();

//   category_combobox=new QComboBox(this);

//   add_subaccount=new QPushButton(tr("Add SubAccount"),this);
//   delete_subaccount=new QPushButton(tr("Delete SubAccount"),this);


  // vbox->addWidget(category_combobox);
  // vbox->addWidget(add_subaccount);
  // vbox->addWidget(delete_subaccount);
   vbox->addWidget(add_deposit);
   vbox->addWidget(withdraw_money);

   hbox->addLayout(vbox);
   this->setLayout(hbox);


   connect(add_deposit,&QPushButton::clicked,this,[this](){
       DialogAddDeposit dia;
       if(dia.exec()==QDialog::Accepted){
           qDebug()<<DEBUG_PRE<<"Add Succedd";
       }else{
           qDebug()<<DEBUG_PRE<<"Deposit Canceled";
       }

   });
   
   
}

void DepositWidget::init_res()
{
//    QSqlQueryModel *combox_model=new QSqlQueryModel(this);
   sqlView=new QTableView(this);
   auto model=new QSqlQueryModel(this);
   QSqlQuery query(DataBaseUtils::getInstance());
   QString tmp=
   "SELECT s_type,benjin,nianxian,lilv,qishi_shijian FROM saving_subaccount WHERE id in("
                   "SELECT sid FROM card_saving WHERE"
                   " cid='%1'"
                   ")";
   QString stmt=tmp.arg(this->ctrl.idcard);
   model->setQuery(query);
   model->setHeaderData(0,Qt::Horizontal,tr("Type"));
   model->setHeaderData(1,Qt::Horizontal,tr("Benjin"));
   model->setHeaderData(2,Qt::Horizontal,tr("nianxian"));
   model->setHeaderData(3,Qt::Horizontal,tr("lilv"));
   model->setHeaderData(4,Qt::Horizontal,tr("qishi_shijian"));

   sqlView->setModel(model);
   add_deposit=new QPushButton(tr("Deposit"),this);
   withdraw_money=new QPushButton(tr("WithDraw"),this);

}
