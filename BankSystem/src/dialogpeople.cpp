#include "dialogpeople.h"

#include <QMessageBox>
#include <QPushButton>
#include <QSqlRecord>
#include <QTimer>

#include "databaseutils.h"
#include <QDebug>
#define DEBUG_PRE "DIALOGPEOPLE"
DIalogPeople::DIalogPeople(QString id):idcard(id)
{

    init_res();
    init_ui();
    init_data();
    connect(btn_add,&QPushButton::clicked,this,[this](){
        if(sqlmodel->insertRow(sqlmodel->rowCount())){
            qDebug()<<DEBUG_PRE<<"INSERT SUCCESSED";
            QMessageBox::information(this,tr("Success"),tr("Add Success"));
            return ;
        }else{
            QMessageBox::warning(this,tr("ERROR"),sqlmodel->lastError().text());
            qDebug()<<DEBUG_PRE<<"INSERT FAILED:"<<sqlmodel->lastError();
            return ;
        }

    });
    connect(btn_delete,&QPushButton::clicked,this,[this](){
        if(!sqlmodel->removeRow(tv_disp->currentIndex().row())){
            qDebug()<<DEBUG_PRE<<"REMOVE FAILED:"<<sqlmodel->lastError();
        }
    });
    connect(sqlmodel,&QSqlTableModel::beforeInsert,this,[this](QSqlRecord &record){
        record.setValue(record.indexOf("idcard"),idcard);
        record.setGenerated(record.indexOf("idcard"),true);

        if(record.isGenerated(record.indexOf("name")
                               )){
            QTimer::singleShot(500,[this](){
//    sqlmodel->setTable("familiar");
//    sqlmodel->setFilter(QString("idcard='%1'").arg(idcard));
//    sqlmodel->setEditStrategy(QSqlTableModel::OnFieldChange);
    sqlmodel->select();
//    tv_disp->hideColumn(2);

            });

        }
        qDebug()<<record;

    });
}

void DIalogPeople::init_res()
{
    layout_main=new QHBoxLayout;
    tv_disp=new QTableView;
    sqlmodel=new QSqlTableModel(this,DataBaseUtils::getInstance());
    layout_rv=new QVBoxLayout;
    btn_add=new QPushButton(tr("ADD"));
    btn_delete=new QPushButton(tr("DELETE"));
}

void DIalogPeople::init_ui()
{
    this->setLayout(layout_main);
    layout_main->addWidget(tv_disp);

    layout_main->addLayout(layout_rv);

    layout_rv->addWidget(btn_add);
    layout_rv->addWidget(btn_delete);

}

void DIalogPeople::init_data()
{
    sqlmodel->setTable("familiar");
    sqlmodel->setFilter(QString("idcard='%1'").arg(idcard));
    sqlmodel->setEditStrategy(QSqlTableModel::OnFieldChange);

    sqlmodel->select();

    tv_disp->setModel(sqlmodel);
    tv_disp->hideColumn(2);

}
