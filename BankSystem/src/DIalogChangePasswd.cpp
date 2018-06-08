//
// Created by 贾庆彤 on 18/6/6.
//

#include "DIalogChangePasswd.h"

#include <QMessageBox>
#include <QPushButton>

DIalogChangePasswd::DIalogChangePasswd(one_card_control &control):ctrl(control){
    init_res();
    init_ui();


}

void DIalogChangePasswd::init_res()
{
    //------1
    this->accept=new QPushButton(tr("Accept"),this);
    this->cancel=new QPushButton(tr("Cancel"),this);

    this->origin_passwd=new QLineEdit(this);
    this->new_passwd=new QLineEdit(this);
    this->ensure_new_passwd=new QLineEdit(this);

    this->main_layout=new QFormLayout(this);

    //------2
    connect(accept,&QPushButton::clicked,this,[this](){
        if(new_passwd->text()!=ensure_new_passwd->text()){
            QMessageBox::warning(this,tr("ERROR"),tr("enw passwd don't match"));
            return;
        }else{
        auto ret=ctrl.change_passwd(origin_passwd->text(),new_passwd->text());
        if(true==ret.first){
            QMessageBox::information(this,tr("OK"),tr("Change success"));
            QDialog::accept();
        }else{
            QMessageBox::warning(this,tr("ERROR"),ret.second);
        }
        }
    });
    connect(cancel,&QPushButton::clicked,this,[this](){QDialog::reject();});



}

void DIalogChangePasswd::init_ui()
{
    main_layout->addRow(tr("Origin Passwd"),origin_passwd);
    main_layout->addRow(tr("New Passwd"),new_passwd);
    main_layout->addRow(tr("Enter Again"),ensure_new_passwd);
    main_layout->addWidget(accept);
    main_layout->addWidget(cancel);

    this->setLayout(main_layout);
}
