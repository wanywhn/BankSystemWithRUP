#include "widgetcreditcard.h"
#include <QInputDialog>
#include <QMessageBox>

WidgetCreditCard::WidgetCreditCard(QString idc, QWidget *parent) : QWidget(parent),ctrl(idc)
{
    init_res();
    init_ui();
    idcard=idc;

}

void WidgetCreditCard::init_ui()
{
    layout_main->addWidget(le_creditcard_id);
    layout_main->addWidget(btn_pay);
    layout_main->addWidget(btn_enchashment);


    connect(btn_pay,&QPushButton::clicked,this,[this](){
        auto id=le_creditcard_id->text();
        //TODO shaoeriweima
        auto ret=ctrl.pay(id,0,"");
        if(ret.first){
            QMessageBox::information(this,tr("Succcess"),tr("Pay Success"));
        }else{
            QMessageBox::warning(this,tr("Error"),ret.second);
        }
    });
    connect(btn_enchashment,&QPushButton::clicked,this,[this](){
        auto id=le_creditcard_id->text();
        auto count=QInputDialog::getDouble(this,tr("Please Input"),tr("Please Input Count"));
        auto passwd=QInputDialog::getText(this,tr("Please Input"),tr("Please Input Psswd"));
        auto ret=ctrl.enchashmen(id,passwd,count);
        if(ret.first){
            QMessageBox::information(this,tr("Success"),tr("Enchashment Success"));
        }else{
            QMessageBox::warning(this,tr("Failed"),ret.second);
        }

    });



}

void WidgetCreditCard::init_res()
{

    this->layout_main=new QVBoxLayout(this);

    this->le_creditcard_id=new QLineEdit;
    this->btn_pay=new QPushButton(tr("Pay"));
    this->btn_enchashment=new QPushButton(tr("enchashment"));


}
