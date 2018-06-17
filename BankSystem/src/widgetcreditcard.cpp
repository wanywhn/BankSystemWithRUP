#include "widgetcreditcard.h"
#include <QInputDialog>
#include <QMessageBox>

#include <QZXing>

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
    layout_main->addWidget(btn_showmsg);
    layout_main->addWidget(lb_img);
    layout_main->addLayout(layout_fl);
    layout_fl->addRow("credit limit",text1);
    layout_fl->addRow("remained limit",text2);
    layout_fl->addRow("lowest payment",text3);


    connect(btn_pay,&QPushButton::clicked,this,[this](){
        auto id=le_creditcard_id->text();
        //TODO shaoeriweima
//        auto ret=ctrl.pay(id,0,"","");
//        if(ret.first){
//            QMessageBox::information(this,tr("Succcess"),tr("Pay Success"));
//        }else{
//            QMessageBox::warning(this,tr("Error"),ret.second);
//        }
        QImage qr=QZXing::encodeData(id);
        lb_img->setPixmap(QPixmap::fromImage(qr));
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
    connect(btn_showmsg,&QPushButton::clicked,this,[this](){
        auto id=le_creditcard_id->text();
        auto ret=ctrl.GetTotalLimit(id);
        auto ret1=ctrl.GetnowLimit(id);
        text1->setText(QString::number(ret));
        text2->setText(QString::number(ret1));

    });



}

void WidgetCreditCard::init_res()
{

    this->layout_main=new QVBoxLayout(this);
    this->layout_fl=new QFormLayout();

    this->le_creditcard_id=new QLineEdit;
    this->btn_pay=new QPushButton(tr("Pay"));
    this->btn_enchashment=new QPushButton(tr("enchashment"));
    this->btn_showmsg=new QPushButton(tr("show messages"));
    lb_img=new QLabel;
    text1=new QLabel;
    text2=new QLabel;
    text3=new QLabel;


}
