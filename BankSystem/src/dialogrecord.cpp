#include "dialogrecord.h"
#include "databaseutils.h"
#include <QPushButton>

#include <QCalendarWidget>
#include <QDate>
#include <QDateEdit>
#include <QDebug>
#include <QSqlQuery>

#define DEBUG_PRE "DialogRecord"
DialogRecord::DialogRecord(QString ocd) : id_card(ocd) {
  init_res();
  init_ui();
  init_data();

  connect(cb_categ, &QComboBox::currentTextChanged, this,
          &DialogRecord::slots_categ_changed);
}

void DialogRecord::init_res() {
  layout_main = new QVBoxLayout;
  layout_fl = new QFormLayout;


  cb_categ = new QComboBox;

  tv_sqlview = new QTableView;
  sqlmodel = new QSqlQueryModel;
}



void DialogRecord::slots_categ_changed(const QString &str) {
  QString tmp = "SELECT type,date,reason,figure FROM consume_log WHERE "
                "cid='%1' ";

  QString stmt = tmp.arg(id_card);
  if(str=="-"){

  }else{
      stmt=stmt.append("AND type='"+str+"'");
  }
  qDebug()<<DEBUG_PRE<<stmt;
  sqlmodel->setQuery(stmt, DataBaseUtils::getInstance());
}

void DialogRecord::init_ui() {
  this->setLayout(layout_main);

  layout_main->addLayout(layout_fl);

  layout_fl->addRow(tr("Cate"), cb_categ);

  layout_main->addWidget(tv_sqlview);
}

void DialogRecord::init_data() {

  QString tmp = "SELECT type FROM consume_log WHERE cid='%1' ";
  auto db = DataBaseUtils::getInstance();
  if (!db.open()) {
    qDebug() << DEBUG_PRE << db.lastError();
    return;
  }
  QSqlQuery query(db);
  if (!query.exec(tmp.arg(id_card))) {
    qDebug() << DEBUG_PRE << query.lastError();
    return;
  }
  while (query.next()) {

      if(!type_list.contains(query.value(0).toString())){
    type_list.append(query.value(0).toString());
      }
  }
  cb_categ->addItems(type_list);
  cb_categ->addItem("-");

  tmp = "SELECT type,date,reason,figure FROM consume_log WHERE cid='%1' ";
  sqlmodel->setQuery(tmp.arg(id_card), DataBaseUtils::getInstance());
  sqlmodel->setHeaderData(0, Qt::Horizontal, tr("Type"));
  sqlmodel->setHeaderData(1, Qt::Horizontal, tr("Date"));
  sqlmodel->setHeaderData(2, Qt::Horizontal, tr("Reason"));
  sqlmodel->setHeaderData(3, Qt::Horizontal, tr("figure"));
  tv_sqlview->setModel(sqlmodel);
}
