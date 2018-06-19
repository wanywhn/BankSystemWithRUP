#include "DIalogChangePasswd.h"
#include "depositwidget.h"
#include "dialogsyslogin.h"
#include "mainwindow.h"
#include "openaccount.h"
#include "systemwidget.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QDir>
#include <QInputDialog>
#include <QInputDialog>
#include <QMessageBox>
#include "widgetcreditcard.h"
#include "widgetonlinebank.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_ui();
    logined=false;
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
    auto log_out=account_menu->addAction(tr("logout"));

    auto depart=this->menuBar()->addMenu(tr("Depart"));
    auto deposit=depart->addAction(tr("&Deposit"));

    auto creditCard=depart->addAction(tr("&CreditCard"));

    auto bank_system=depart->addAction(tr("&Bank System"));

    auto online_bank=depart->addAction(tr("Online Bank"));

    //------2
    connect(log_out,&QAction::triggered,this,[this](){
        logined=false;
        QMessageBox::information(this,tr("Success"),tr("Logout Success"));

    });
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
        }
        if(!this->card_ctrl.set_onecard(id)){
            QMessageBox::warning(this,tr("Error"),tr("Can't find the card,please login again"));
            return ;
        }
        if(card_ctrl.is_lost()){
            QMessageBox::warning(this,tr("Error"),tr("The Card Have Been lost"));
            return ;
        }
        QMessageBox::information(this,tr("Success"),tr("You have Login in"));
        logined=true;


    });
    connect(change_passwd,&QAction::triggered,this,[this](){
        if(!logined){
            QMessageBox::warning(this,tr("Error"),tr("Please Login!"));
            return ;
        }
        DIalogChangePasswd dialog(card_ctrl);
        if(dialog.exec()==QDialog::Accepted){
            qDebug()<<"Change passwd successed";
        }else{
            qDebug()<<"Change passwd failed";
        }
    });
    connect(loss_reporting,&QAction::triggered,this,[this](){
        if(!logined){
            QMessageBox::warning(this,tr("Error"),tr("Please Login!"));
            return ;
        }

        auto ret=QMessageBox::question(this,tr("Confirm"),tr("Sure loss report?"));
        if(QMessageBox::Yes==ret||QMessageBox::Ok==ret){
            if(card_ctrl.set_loss()){

            QMessageBox::information(this,tr("Success"),tr("Set loss success"));
            }else{
                QMessageBox::warning(this,tr("Error"),tr("set loss failed"));
            }
        }else{
            qDebug()<<"User Cancel loss report";
        }
    });

    connect(cancel_loss_reporting,&QAction::triggered,this,[this](){
        QString id=QInputDialog::getText(this,tr("Please input "),tr("Please Input onecard id"));
        if(id.isEmpty()){
                return ;
    }
        card_ctrl.set_onecard(id);
        auto ret=card_ctrl.cancel_loss();
        if(ret.first){
            QMessageBox::information(this,tr("Success"),tr("DONE"));
        }else{
            QMessageBox::warning(this,tr("Error"),ret.second);
        }
        card_ctrl.set_onecard("");
    });
    connect(reapply_onecard,&QAction::triggered,this,[this](){
        if(!logined){
            QMessageBox::warning(this,tr("Error"),tr("Please Login!"));
            return ;
        }
        auto ret=card_ctrl.reapply_one_card();
        if(ret.first){
            QMessageBox::information(this,tr("Success"),tr("DONE"));
        }else{
            QMessageBox::warning(this,tr("Error"),ret.second);
        }
    });
    connect(open_online_bank,&QAction::triggered,this,[this](){
        if(!logined){
            QMessageBox::warning(this,tr("Error"),tr("Please Login!"));
            return ;
        }
        bool ok;
        auto name=QInputDialog::getText(this,tr("Input"),tr("Please Input UserName"),QLineEdit::Normal,QDir::home().dirName(),&ok);
        if(!ok){
            return ;
        }
        auto passwd=QInputDialog::getText(this,tr("Input"),tr("Please Input Passwd"),QLineEdit::PasswordEchoOnEdit,QDir::home().dirName(),&ok);
        if(!ok){
            return ;
        }
        //TODO checko format


        auto ret=card_ctrl.open_online_bank_system_of(name,passwd);
        if(ret.first){
            QMessageBox::information(this,tr("Success"),tr("Open online bank successed"));
        }else{
            QMessageBox::warning(this,tr("Error"),ret.second);
        }
    });



    connect(deposit,&QAction::triggered,[this](){
        if(!logined){
            QMessageBox::warning(this,tr("Error"),tr("Please Login!"));
            return ;
        }

        auto wid=new DepositWidget(card_ctrl,this);
        this->setCentralWidget(wid);
    });
    connect(creditCard,&QAction::triggered,[this](){
        auto wid=new WidgetCreditCard(card_ctrl.get_idcard());
        this->setCentralWidget(wid);
    });
    connect(bank_system,&QAction::triggered,[this](){

    DialogSysLogin dia(sctrl);
    if(dia.exec()!=QDialog::Accepted){
        return;
    }
    static auto sys=new SystemWidget(this);
    this->setCentralWidget(sys);
    });

    connect(online_bank,&QAction::triggered,this,[this](){
        DialogSysLogin dia(octrl);
        if(dia.exec()!=QDialog::Accepted){
            return ;
        }
        auto wid=new WidgetOnlineBank(octrl);
        this->setCentralWidget(wid);


    });

}
