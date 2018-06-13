#include "dialogsyslogin.h"

#include <QFormLayout>
#include <QMessageBox>
#include <QInputDialog>

DialogSysLogin::DialogSysLogin(interface_ctrl &ctrl):ctrl(ctrl)
{

    init_res();
    init_ui();
}

void DialogSysLogin::init_ui()
{
    auto layout=new QFormLayout(this);
    layout->addRow(tr("SysUserName"),name);
    layout->addRow(tr("Passwd"),passwd);
    layout->addRow(login,changePasswd);
    layout->addWidget(canc);


    connect(login,&QPushButton::clicked,this,[this](){
        auto ret=ctrl.login(this->name->text(),this->passwd->text());
        if(ret.first){
            QMessageBox::information(this,tr("Success"),tr("Login Successed"));
            this->accept();
        }else{
            QMessageBox::warning(this,tr("Failed"),ret.second);
        }
    });
    connect(changePasswd,&QPushButton::clicked,this,[this](){
        auto name=QInputDialog::getText(this,tr("Please Input"),tr("UserName"));
        auto ori=QInputDialog::getText(this,tr("Please Input"),tr("Origin Passwd"));
        auto n=QInputDialog::getText(this,tr("Please Input"),tr("New Passwd"));
        auto n2=QInputDialog::getText(this,tr("Please Input"),tr("Enter New Passwd Again"));
        if(n!=n2){
            QMessageBox::warning(this,tr("Error"),tr("New Passwd don't same"));
            return;
        }
        auto ret=ctrl.change_passwd(name,ori,n);
        if(ret.first){
            QMessageBox::information(this,tr("Success"),tr("Passwd Change Success"));
            this->accepted();
        }else{
            QMessageBox::warning(this,tr("Failed"),ret.second);
        }
    });
    connect(canc,&QPushButton::clicked,this,[this](){
        this->reject();
    });

}

void DialogSysLogin::init_res()
{
    this->name=new QLineEdit;
    this->passwd=new QLineEdit;
    this->login=new QPushButton(tr("Login"));
    this->changePasswd=new QPushButton(tr("ChangePasswd"));
    this->canc=new QPushButton(tr("Cancel"));

}
