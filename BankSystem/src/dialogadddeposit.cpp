#include "dialogadddeposit.h"

#include <QFormLayout>

DialogAddDeposit::DialogAddDeposit()
{
    init_res();
    init_ui();

}

void DialogAddDeposit::init_res()
{
    tb_center=new QTabWidget(this);
    fixed=new QWidget;
    huoqi=new QWidget;
    dinghuo=new QWidget;

    le_lilv=new QLineEdit;
    rb_autocontinue=new QRadioButton;
    le_cunqi=new QLineEdit;
    le_benjin=new QLineEdit;

}

void DialogAddDeposit::init_ui()
{
    //------1
    auto fixed_layout=new QFormLayout(fixed);
    fixed_layout->addRow(tr("Benjin"),le_benjin);
    fixed_layout->addRow(tr("Cunqi"),le_cunqi);
    fixed_layout->addRow(tr("Lilv"),le_lilv);
    fixed_layout->addRow(tr("Auto Continue"),rb_autocontinue);



    tb_center->addTab(fixed,tr("Fixed"));
    tb_center->addTab(huoqi,tr("Current"));
    tb_center->addTab(dinghuo,tr("Dinghuo"));


    QHBoxLayout *h=new QHBoxLayout(this);
    h->addWidget(tb_center);
}
