#include <QLabel>
#include <QMessageBox>
#include "openaccount.h"

OpenAccount::OpenAccount(one_card_control &card_ctrl):ctrl(card_ctrl)
{
    init_res();
    init_ui();


}

void OpenAccount::init_res()
{
    main_layout=new QFormLayout;
    name=new QLineEdit(this);
    idcard=new QLineEdit(this);
    address=new QLineEdit(this);
    phone=new QLineEdit(this);
    passwd=new QLineEdit(this);

    accept=new QPushButton(tr("Accept"));
    denay=new QPushButton(tr("Denay"));

}

void OpenAccount::init_ui()
{
        main_layout->addRow("Name",name);
        main_layout->addRow("IDCARD",idcard);
        main_layout->addRow("ADDRESS",address);
        main_layout->addRow("PHONE",phone);
    main_layout->addRow("PASSWD",passwd);


    main_layout->addWidget(accept);
    main_layout->addWidget(denay);

    connect(accept,&QPushButton::clicked,this,[this](){

        auto ret=ctrl.register_user(name->text(),idcard->text(),address->text(),phone->text(),passwd->text());
        if(ret.first){
            QMessageBox::information(this,tr("Success"),tr("Create Account Success"));
        QDialog::accept();
        }else{
            QMessageBox::warning(this,tr("Failed"),ret.second);
        }

    });
    connect(denay,&QPushButton::clicked,this,[this](){
        QDialog::reject();
    });

    setLayout(main_layout);

}



