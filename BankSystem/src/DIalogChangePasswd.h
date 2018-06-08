//
// Created by 贾庆彤 on 18/6/6.
//

#ifndef BANKSYSTEM_DIALOGCHANGEPASSWD_H
#define BANKSYSTEM_DIALOGCHANGEPASSWD_H


#include <QDialog>
#include "gen/App_Layer.h"
#include <QFormLayout>
#include <QLineEdit>

class DIalogChangePasswd : public QDialog{

public:
    explicit DIalogChangePasswd(one_card_control &control);


private:
    one_card_control &ctrl;

    QPushButton *accept;
    QPushButton *cancel;

    QLineEdit *origin_passwd;
    QLineEdit *new_passwd;
    QLineEdit *ensure_new_passwd;

    QFormLayout *main_layout;

private:
    void init_res();
    void init_ui();


};


#endif //BANKSYSTEM_DIALOGCHANGEPASSWD_H
