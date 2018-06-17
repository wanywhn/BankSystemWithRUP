#include "databaseutils.h"
#include "depositwidget.h"
#include "dialogadddeposit.h"

#include <QHBoxLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define DEBUG_PRE __FILE__ "DepositWidget:" TOSTRING(__LINE__)
DepositWidget::DepositWidget(one_card_control &ctrl, QWidget *parent):ctrl(ctrl)
{
    init_res();
    init_ui();
}

void DepositWidget::init_ui()
{


   auto hbox=new QHBoxLayout(this);

   hbox->addWidget(sqlView);

   auto vbox=new QVBoxLayout();

   vbox->addWidget(add_deposit);
   vbox->addWidget(withdraw_money);

   hbox->addLayout(vbox);


   connect(add_deposit,&QPushButton::clicked,this,[this](){
       //TODO current should add into one sub_account;
       DialogAddDeposit dia(ctrl);
       if(dia.exec()==QDialog::Accepted){
           qDebug()<<DEBUG_PRE<<"Add Succedd";
          model->setQuery(query_stmt,DataBaseUtils::getInstance());
       }else{
           qDebug()<<DEBUG_PRE<<"Deposit Canceled";
       }

   });
   connect(withdraw_money,&QPushButton::clicked,this,[this](){
      auto select=sqlView->selectionModel();
      auto rows=select->selectedRows(0);
      if(rows.size()==0){
          QMessageBox::warning(this,tr("Error"),tr("Please Select a row"));
          return ;
      }
      auto tmp=QInputDialog::getInt(this,tr("Input"),tr("Please Input count"));
      int id=rows.at(0).data().toInt();
      qDebug()<<DEBUG_PRE<<id;
      auto ret=ctrl.withdraw(id,tmp,"WithDraw From qiantai","WITHDRAW");

      if(ret.first==true){
          QMessageBox::information(this,tr("Success"),tr("withdraw Success"));
          model->setQuery(query_stmt,DataBaseUtils::getInstance());
      }else{
          QMessageBox::warning(this,tr("Failed"),ret.second);

      }


   });
   
   
}

void DepositWidget::init_res()
{
//    QSqlQueryModel *combox_model=new QSqlQueryModel(this);
   sqlView=new QTableView(this);
   model=new QSqlQueryModel(this);
//   QSqlQuery query(DataBaseUtils::getInstance());
   QString tmp=
   "SELECT id,s_type,m_type,benjin,nianxian,lilv,qishi_shijian FROM saving_subaccount WHERE cid = '%1' ";
   query_stmt=tmp.arg(this->ctrl.onecard);
   model->setQuery(query_stmt,DataBaseUtils::getInstance());
   model->setHeaderData(0,Qt::Horizontal,tr("ID"));
   model->setHeaderData(1,Qt::Horizontal,tr("Deposit Type"));
   model->setHeaderData(2,Qt::Horizontal,tr("Money Type"));
   model->setHeaderData(3,Qt::Horizontal,tr("Benjin"));
   model->setHeaderData(4,Qt::Horizontal,tr("nianxian"));
   model->setHeaderData(5,Qt::Horizontal,tr("lilv"));
   model->setHeaderData(6,Qt::Horizontal,tr("qishi_shijian"));

   sqlView->setModel(model);
   sqlView->setSelectionMode(QAbstractItemView::SingleSelection);
   sqlView->setSelectionBehavior(QAbstractItemView::SelectRows);
   add_deposit=new QPushButton(tr("Deposit"),this);
   withdraw_money=new QPushButton(tr("WithDraw"),this);

}
