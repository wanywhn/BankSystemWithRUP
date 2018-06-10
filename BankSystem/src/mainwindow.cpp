#include "DIalogChangePasswd.h"
#include "depositwidget.h"
#include "dialogsyslogin.h"
#include "mainwindow.h"
#include "openaccount.h"
#include "systemwidget.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QInputDialog>
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

    auto depart=this->menuBar()->addMenu(tr("Depart"));
    auto deposit=depart->addAction(tr("&Deposit"));

    auto creditCard=depart->addAction(tr("&CreditCard"));

    auto bank_system=depart->addAction(tr("&Bank System"));

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
        auto id=QInputDialog::getText(this,tr("Input info"),tr("Please Input One Card"));
        if(id.isEmpty()){
            QMessageBox::warning(this,tr("Warning"),tr("You have enter a wrong One Card"));
            return;
        }else{
            this->card_ctrl.set_onecard(id);
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
    connect(loss_reporting,&QAction::triggered,this,[this](){

        auto ret=QMessageBox::question(this,tr("Confirm"),tr("Sure loss report?"));
        if(QMessageBox::Yes==ret||QMessageBox::Ok==ret){
            card_ctrl.set_loss();
        }else{
            qDebug()<<"User Cancel loss report";
        }
    });

    connect(cancel_loss_reporting,&QAction::triggered,this,[this](){
        auto ret=card_ctrl.cancel_loss();
        if(ret.first==true){
            QMessageBox::information(this,tr("Success"),tr("DONE"));
        }else{
            QMessageBox::warning(this,tr("Error"),ret.second);
        }
    });
    connect(reapply_onecard,&QAction::triggered,this,[this](){
        auto ret=card_ctrl.reapply_one_card();
        if(ret.first==true){
            QMessageBox::information(this,tr("Success"),tr("DONE"));
        }else{
            QMessageBox::warning(this,tr("Error"),ret.second);
        }
    });
    connect(open_online_bank,&QAction::triggered,this,[this](){
        auto name=QInputDialog::getText(this,tr("Input"),tr("Please Input UserName"));
        auto passwd=QInputDialog::getText(this,tr("Input"),tr("Please Input Passwd"));
        //TODO checko format


        auto ret=card_ctrl.open_online_bank_system_of(name,passwd);
        if(ret.first){
            QMessageBox::information(this,tr("Success"),tr("Open online bank successed"));
        }else{
            QMessageBox::warning(this,tr("Error"),ret.second);
        }
    });



    connect(deposit,&QAction::triggered,[this](){

        static auto wid=new DepositWidget(card_ctrl,this);
        this->setCentralWidget(wid);
    });
    connect(creditCard,&QAction::triggered,[this](){



    });
    connect(bank_system,&QAction::triggered,[this](){});
    DialogSysLogin dia;
    if(dia.exec()!=QDialog::Accepted){
        return;
    }
    static auto sys=new SystemWidget(this);
    this->setCentralWidget(sys);

}
