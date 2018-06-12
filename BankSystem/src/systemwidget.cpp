#include "databaseutils.h"
#include "dialogsyslogin.h"
#include "systemwidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>

#define DEBUG_PRE "SystemWidget"
SystemWidget::SystemWidget(QWidget *parent) : QWidget(parent)
{

    init_res();
    init_ui();

    connect(btn_accept,&QPushButton::clicked,this,&SystemWidget::update_data);
    connect(btn_reset,&QPushButton::clicked,this,&SystemWidget::reset_date);
    reset_date();

}

void SystemWidget::update_data()
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<db.lastError();
    }

    QString tmp="UPDATE lilv SET current='%1',one_year='%2',five_year='%3',daikuan='%4',credit_enchashment_fee='%5',"
                "credit_lixi='%6',credit_overdue_fine='%7',usd='%8',yen='%9',euro='%10' ";
    QSqlQuery query(db);
    auto value1=le_deposit_current->text().toFloat();
    auto value2=le_deposit_one_year->text().toFloat();
    auto value3=le_deposit_five_year->text().toFloat();
    auto value4=le_credit_enchashment_fee->text().toFloat();
    auto value5=le_deposit_current->text().toFloat();
    auto value6=le_deposit_current->text().toFloat();
    auto value7=le_deposit_current->text().toFloat();
    auto value8=le_deposit_current->text().toFloat();
    auto value9=le_deposit_current->text().toFloat();
    auto value10=le_deposit_current->text().toFloat();

    if(!query.exec(tmp.arg(value1).arg(value2).arg(value3).arg(value3).arg(value4).arg(value5)
                   .arg(value6).arg(value7).arg(value8).arg(value9).arg(value10))){
        qDebug()<<query.lastError();
    }
    QMessageBox::information(this,tr("Success"),tr("Update Success"));


}

void SystemWidget::reset_date()
{
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){
        qDebug()<<DEBUG_PRE<<db.lastError();
        return ;
    }
    //------1 Deposit
    //						0		1		2		3			4					5				6				7	8	9
    QString tmp="SELECT current,one_year,five_year,daikuan,credit_enchashment_fee,"
                "credit_lixi,credit_overdue_fine,usd,yen,euro "
                "FROM lilv ";
    QSqlQuery query(db);
    if(!query.exec(tmp)){
        qDebug()<<DEBUG_PRE<<query.lastError();
        return ;
    }
    query.next();
    le_deposit_current->setText(QString::number(query.value(0).toFloat()));
    le_deposit_one_year->setText(QString::number(query.value(1).toFloat()));
    le_deposit_five_year->setText(QString::number(query.value(2).toFloat()));

    le_credit_enchashment_fee->setText(QString::number(query.value(4).toFloat()));
    le_credit_interest->setText(QString::number(query.value(5).toFloat()));

    le_waihui_usd->setText(QString::number(query.value(7).toFloat()));
    le_waihui_yen->setText(QString::number(query.value(8).toFloat()));
    le_waihui_euro->setText(QString::number(query.value(9).toFloat()));

}

void SystemWidget::init_ui()
{
    layout_main->addWidget(gb_credit_card,0,0);
    layout_main->addWidget(gb_daikuan,0,1);
    layout_main->addWidget(gb_deposit,1,0);
    layout_main->addWidget(gb_waihui,1,1);

    layout_main->addWidget(btn_accept,2,0);
    layout_main->addWidget(btn_reset,2,1);




    gb_credit_card->setLayout(fl_credit_card);
    gb_daikuan->setLayout(fl_daikuan);
    gb_deposit->setLayout(fl_deposit);
    gb_waihui->setLayout(fl_waihui);

    fl_credit_card->addRow(tr("CreditCard Interest"),le_credit_interest);
    fl_credit_card->addRow(tr("Enchashment fee"),le_credit_enchashment_fee);

    fl_daikuan;

    fl_deposit->addRow(tr("Current INterest"),le_deposit_current);
    fl_deposit->addRow(tr("One INterest"),le_deposit_one_year);
    fl_deposit->addRow(tr("Five INterest"),le_deposit_five_year);

    fl_waihui->addRow(tr("EURO"),le_waihui_euro);
    fl_waihui->addRow(tr("USD"),le_waihui_usd);
    fl_waihui->addRow(tr("YEN"),le_waihui_yen);


}

void SystemWidget::init_res()
{
    layout_main=new QGridLayout(this);

    gb_credit_card=new QGroupBox(tr("Credit Card"));
    gb_daikuan=new QGroupBox(tr("Daikuan"));
    gb_deposit=new QGroupBox(tr("Deposit"));
    gb_waihui=new QGroupBox(tr("Wai hui"));

    fl_waihui=new QFormLayout();
    fl_credit_card=new QFormLayout();
    fl_daikuan=new QFormLayout();
    fl_deposit=new QFormLayout();

    le_credit_interest=new QLineEdit;
    le_credit_enchashment_fee=new QLineEdit;

    le_deposit_current=new QLineEdit;
    le_deposit_five_year=new QLineEdit;
    le_deposit_one_year=new QLineEdit;

    le_waihui_euro=new QLineEdit;
    le_waihui_usd=new QLineEdit;
    le_waihui_yen=new QLineEdit;


}

