#include "DIalogChangePasswd.h"
#include "depositwidget.h"
#include "mainwindow.h"
#include "openaccount.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_ui();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_ui()
{
    //------1
    auto account_menu=this->menuBar()->addMenu(tr("&Account"));
    auto open_one_card=account_menu->addAction(tr("&Open One-Card"));
    account_menu->addSeparator();

    auto read_one_card=account_menu->addAction(tr("&Read One-Card"));
    account_menu->addSeparator();

    auto change_passwd=account_menu->addAction(tr("&Change Passwd"));
    auto loss_reporting=account_menu->addAction(tr("&Loss Reporting"));
    auto cancel_loss_reporting=account_menu->addAction(tr("&Cancel Loss Reporting"));
    auto reapply_onecard=account_menu->addAction(tr("&Reapply One Card"));
    auto open_online_bank=account_menu->addAction(tr("&Open Online Bank"));

    auto deposit=this->menuBar()->addAction(tr("&Deposit"));

    auto creditCard=this->menuBar()->addAction(tr("&CreditCard"));

    auto bank_system=this->menuBar()->addAction(tr("&Bank System"));

    //------2
    connect(open_one_card,&QAction::triggered,this,[this](){
        OpenAccount dialog(card_ctrl);
        if(dialog.exec()==QDialog::Accepted){
            qDebug()<<"Open Account Success";
        }else{
            qDebug()<<"User Cancel the OpenAccount ";
        }

    });
    connect(read_one_card,&QAction::triggered,this,[this](){
        auto id=QInputDialog::getText(this,tr("Input info"),tr("Please Input ID Card"));
        if(id.isEmpty()){
            QMessageBox::warning(this,tr("Warning"),tr("You have enter a wrong ID Card"));
            return;
        }else{
        this->card_ctrl.set_idcard(id);
        }
    });
    connect(change_passwd,&QAction::triggered,this,[this](){
        DIalogChangePasswd dialog(card_ctrl);
        if(dialog.exec()==QDialog::Accepted){
            qDebug()<<"Change passwd successed";
        }else{
            qDebug()<<"Change passwd failed";
        }
    });






    connect(deposit,&QAction::triggered,[this](){this->setCentralWidget(new DepositWidget(this));});
    connect(creditCard,&QAction::triggered,[this](){});
    connect(bank_system,&QAction::triggered,[this](){});

}
