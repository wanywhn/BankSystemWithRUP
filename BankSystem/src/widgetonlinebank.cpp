#include "widgetonlinebank.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QModelIndexList>
#include <QMessageBox>

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
}

void WidgetOnlineBank::show_record()
{

}

void WidgetOnlineBank::slots_transfer()
{
    auto m=tv_lview->selectionModel();
    auto row=m->selectedRows();
    
    if(row.size()==0||row.at(0).data().toString().at(1)!="1"){
        QMessageBox::warning(this,tr("Error"),tr("You Should Select a Current subaccount"));
        return ;
    }
    
    


        
    

}

void WidgetOnlineBank::show_analy()
{

}

void WidgetOnlineBank::slots_loss_report()
{
    //TODO xijie
    one_card_account account(this->cb_onecard->currentText());
    account.set_loss(true);
}

void WidgetOnlineBank::slots_people()
{

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
