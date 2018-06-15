#include "databaseutils.h"
#include "dialogrecord.h"
#include <QPushButton>

#include <QDate>
#include<QDebug>
#include <QSqlQuery>

#define DEBUG_PRE "DialogRecord"
DialogRecord::DialogRecord(QString ocd):one_card(ocd)
{
    init_res();
    init_ui();
    init_data();

    connect(btn_select_date,&QPushButton::clicked,this,&DialogRecord::slots_select_date);
    connect(btn_refersh,&QPushButton::clickd,this,&DialogRecord::slots_refersh);
}

void DialogRecord::init_res()
{
    layout_main=new QVBoxLayout;
    layout_fl=new QFormLayout;

    btn_select_date=new QPushButton(tr("Select Date"));
    btn_refersh=new QPushButton(tr("Refersh"));

    cb_categ=new      QComboBox;

    tv_sqlview=new QTableView;


}

void DialogRecord::init_ui(){
    this->setLayout(layout_main);

    layout_main->addLayout(layout_fl);

    layout_fl->addRow(tr("Select Date"),btn_select_date);
    layout_fl->addRow(tr("Cate"),cb_categ);
    layout_fl->addRow(tr("Refersh"),btn_refersh);


    layout_main->addWidget(tv_sqlview);
}

void DialogRecord::init_data(){

    QString tmp="SELECT type FROM consume_log WHERE cardid='%1' ";
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<db.lastError();
        return ;
    }
    QSqlQuery query(db);
    if(!query.exec(tmp.arg(one_card))){
        qDebug()<<DEBUG_PRE<<query.lastError();
        return;
    }
    cb_categ->addItems(type_list);
    cb_categ->addItem("-");
    while(query.next()){

        type_list.append(query.value(0).toString());
    }

    tmp="SELECT type,date,reason,figure FROM consume_log WHERE cardid='%1' ";
    sqlmodel->setQuery(tmp.arg(one_card),DataBaseUtils::getInstance());
    sqlmodel->setHeaderData(0,Qt::Horizontal,tr("Type"));
    sqlmodel->setHeaderData(1,Qt::Horizontal,tr("Date"));
    sqlmodel->setHeaderData(2,Qt::Horizontal,tr("Reason"));
    sqlmodel->setHeaderData(3,Qt::Horizontal,tr("figure"));
    tv_sqlview->setModel(sqlmodel);



}
