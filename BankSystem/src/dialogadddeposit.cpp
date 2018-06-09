#include "dialogadddeposit.h"

#include <QFormLayout>
#include <QMessageBox>

DialogAddDeposit::DialogAddDeposit(one_card_control &c):ctrl(c)
{
    init_res();
    init_ui();

}

void DialogAddDeposit::init_res()
{
//    tb_center=new QTabWidget(this);
//    fixed=new QWidget;
//    huoqi=new QWidget;
//    dinghuo=new QWidget;

    lb_lilv=new QLabel;
    rb_autocontinue=new QRadioButton;
    cb_cunqi=new QComboBox;
    cb_money_kind=new QComboBox;
    cb_deposit_kind=new QComboBox;
    le_benjin=new QLineEdit;

    btn_accept=new QPushButton("Accept");
    btn_calcen=new QPushButton("Cancel");
}

void DialogAddDeposit::init_ui()
{
    //------1
    cb_deposit_kind->addItems({"Fixed","Current","Dinghuo"});
    cb_money_kind->addItems({"1","2","3","4"});
    cb_cunqi->addItems({"1","2","5"});





    QVBoxLayout *h=new QVBoxLayout(this);
//    h->addWidget(tb_center);

    auto common=new QFormLayout;
    common->addRow(tr("Deposit Kind"),cb_deposit_kind);
    common->addRow(tr("Benjin"),le_benjin);
    common->addRow(tr("Lilv"),lb_lilv);
    common->addRow(tr("Money Kind"),cb_money_kind);
    common->addRow(tr("Cunqi"),cb_cunqi);
    common->addRow(tr("Auto Continue"),rb_autocontinue);

    common->addRow(btn_accept,btn_calcen);

    h->addLayout(common);



    connect(cb_deposit_kind,static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),this,[this,common](int index){

        static int last=0;
        if(index==0||index==2){
            if(last==0){

            }else{
                cb_cunqi=new QComboBox;
    cb_cunqi->addItems({"1","2","5"});
                rb_autocontinue=new QRadioButton;

    common->insertRow(4,"Cunqi",cb_cunqi);
    common->insertRow(4,"Auto Continue",rb_autocontinue);
    last=0;
            }
        }else{
            common->removeRow(4);
            common->removeRow(4);
            last=1;

        }

    });

    connect(btn_accept,&QPushButton::clicked,this,[this](){
        this->process_btn(cb_deposit_kind->currentIndex());
    });
}

void DialogAddDeposit::process_btn(int type)
{
    //TODO add check
    int mk=cb_money_kind->currentIndex();
    int bj=le_benjin->text().toInt();
    int cq=cb_cunqi->currentText().toInt();
    float ll=lb_lilv->text().toFloat();
    bool  ac=rb_autocontinue->isChecked();

    auto ret=ctrl.deposit(mk,type,bj,cq,ll,ac);
    if(ret.first){
        QMessageBox::information(this,tr("Success"),tr("Deposit Success"));
    }else{
        QMessageBox::warning(this,tr("Failed"),ret.second);
    }

}
