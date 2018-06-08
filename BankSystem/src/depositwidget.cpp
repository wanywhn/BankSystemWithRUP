#include "databaseutils.h"
#include "depositwidget.h"

#include <QHBoxLayout>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>

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
   
   
}

void DepositWidget::init_res()
{
//    QSqlQueryModel *combox_model=new QSqlQueryModel(this);
   sqlView=new QTableView(this);
   auto model=new QSqlQueryModel(this);
   QSqlQuery query(DataBaseUtils::getInstance());
   query.prepare("SELECT * FROM saving_subaccount WHERE id in("
                   "SELECT sid FROM card_saving WHERE"
                   " cid=':i'"
                   ")");
   query.bindValue(":i",QVariant(this->ctrl.idcard));
   model->setQuery(query);

   add_deposit=new QPushButton(tr("Deposit"),this);
   withdraw_money=new QPushButton(tr("WithDraw"),this);

}
