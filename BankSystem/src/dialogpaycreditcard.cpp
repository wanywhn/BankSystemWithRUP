#include "dialogpaycreditcard.h"
#include <QMessageBox>

DialogPayCreditCard::DialogPayCreditCard(QString idcard, QString sid, QString ocd):idcard(idcard),cctrl(idcard)
{
    octrl.set_idcard(idcard);
    this->sid=sid;
    this->ocd=ocd;
    init_res();
    init_ui();;
    init_data();

    connect(btn_accept,&QPushButton::clicked,this,&DialogPayCreditCard::slots_pay);
    connect(cb_creditcard,&QComboBox::currentTextChanged,this,[this](QString str){
    lb_least->setText(QString::number(cctrl.Getminvalue(str)));
    lb_own->setText(QString::number(cctrl.Getminvalue(str)));
    });
            
    
}

void DialogPayCreditCard::slots_pay()
{
    auto count=le_num->text().toInt();
    if(count<lb_least->text().toFloat()){
        QMessageBox::warning(this,tr("ERROR"),tr("you should pay least ")+lb_least->text());
        return;
    }
    if(count>lb_own->text().toFloat()){
        QMessageBox::warning(this,tr("ERROR"),tr("Too much money"));
        return ;
    }
    one_card_account tmp(ocd);
    tmp.withdrawal_money(sid.toInt(),count,tr("Pay Owned Credit Card"),tr("PAY CREDITCARD"));

    if(!cctrl.pay_own(cb_creditcard->currentText(),count)){
        QMessageBox::warning(this,tr("Error"),tr("Pay Error"));
    }
    init_data();
    
}

void DialogPayCreditCard::init_res()
{
    layout_main=new QFormLayout(this);

    cb_creditcard=new QComboBox;
    lb_least=new QLabel;
    lb_own=new QLabel;

    le_num=new QLineEdit;

    btn_accept=new QPushButton(tr("Accept"));

    btn_calcen=new QPushButton(tr("cancel"));

}

void DialogPayCreditCard::init_ui()
{
    layout_main->addRow(tr("SELECT CreditCard"),cb_creditcard);
    layout_main->addRow(tr("Own"),lb_own);
    layout_main->addRow(tr("Lease"),lb_least);

    layout_main->addRow(tr("TO pay"),le_num);

    layout_main->addRow(btn_accept,btn_calcen);

}

void DialogPayCreditCard::init_data()
{
    auto list=cctrl.getCreditCards(idcard);
    cb_creditcard->clear();
    cb_creditcard->addItems(list);
    lb_least->setText(QString::number(cctrl.Getminvalue(cb_creditcard->currentText())));
    lb_own->setText(QString::number(cctrl.Getminvalue(cb_creditcard->currentText())));

}
