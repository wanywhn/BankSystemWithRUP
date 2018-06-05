#include "depositwidget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
void init_ui();

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
    auto account_menu=this->menuBar()->addMenu(tr("A&ccount"));
    auto open_one_card=account_menu->addAction(tr("&Open One-Card"));
    account_menu->addSeparator();

    auto read_one_card=account_menu->addAction(tr("&Read One-Card"));
    account_menu->addSeparator();



    auto change_passwd=account_menu->addAction(tr("&Change Passwd"));
    auto loss_reporting=account_menu->addAction(tr("&Loss Reporting"));
    auto cancel_loss_reporting=account_menu->addAction(tr("&Cancel Loss Reporting"));
    auto reapply_onecard=account_menu->addAction(tr("&Reapply One Card"));


    auto deposit=this->menuBar()->addAction(tr("&Deposit"));
    connect(deposit,&QAction::triggered,[this](){this->setCentralWidget(new DepositWidget(this));});

    auto creditCard=this->menuBar()->addAction(tr("&CreditCard"));
    connect(creditCard,&QAction::triggered,[this](){});

    auto bank_system=this->menuBar()->addAction(tr("&Bank System"));
    connect(bank_system,&QAction::triggered,[this](){});

}
