#include "widgetonlinebank.h"

WidgetOnlineBank::WidgetOnlineBank(QWidget *parent) : QWidget(parent)
{

    init_res();
    init_ui();
}

void WidgetOnlineBank::init_res()
{

    layout_main=new QHBoxLayout;
    layout_rv=new QVBoxLayout;

    tv_lview=new QTableView;

    btn_analy=new QPushButton(tr("Analysis"));
    btn_change_passwd=new QPushButton(tr("Change Passwd"));
    btn_loss_report=new QPushButton(tr("Loss Report"));
    btn_record=new QPushButton(tr("Recode"));
    btn_transfer=new QPushButton(tr("Transfer"));

    sqlmodel=new QSqlQueryModel;

}

void WidgetOnlineBank::init_ui()
{
    this->setLayout(layout_main);

    layout_main->addWidget(tv_lview);
    layout_main->addLayout(layout_rv);

    layout_rv->addWidget(btn_analy);
    layout_rv->addWidget(btn_change_passwd);
    layout_rv->addWidget(btn_loss_report);
    layout_rv->addWidget(btn_record);
    layout_rv->addWidget(btn_transfer);
}
