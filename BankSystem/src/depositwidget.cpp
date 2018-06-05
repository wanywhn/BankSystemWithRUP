#include "depositwidget.h"

#include <QHBoxLayout>
#include <QSqlQueryModel>
DepositWidget::DepositWidget(QWidget *parent) : QWidget(parent)
{

    init_ui();
    init_res();



}

void DepositWidget::init_ui()
{

   sqlView=new QTableView(this);

   auto hbox=new QHBoxLayout();

   hbox->addWidget(sqlView);

   auto vbox=new QVBoxLayout();

   category_combobox=new QComboBox(this);

   add_subaccount=new QPushButton(tr("Add SubAccount"),this);
   delete_subaccount=new QPushButton(tr("Delete SubAccount"),this);

   add_deposit=new QPushButton(tr("Deposit"),this);
   withdraw_money=new QPushButton(tr("WithDraw"),this);

   vbox->addWidget(category_combobox);
   vbox->addWidget(add_subaccount);
   vbox->addWidget(delete_subaccount);
   vbox->addWidget(add_deposit);
   vbox->addWidget(withdraw_money);

   hbox->addLayout(vbox);
   this->setLayout(hbox);
   
   
}

void DepositWidget::init_res()
{
    QSqlQueryModel *combox_model=new QSqlQueryModel(this);
    
}
