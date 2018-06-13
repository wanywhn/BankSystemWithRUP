#ifndef DIALOGSYSLOGIN_H
#define DIALOGSYSLOGIN_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

#include "gen/BankSystem.h"


class DialogSysLogin : public QDialog
{
public:
    DialogSysLogin(interface_ctrl &ctrl);


private:
    void init_ui();
    void init_res();


private:
    QLineEdit *name;
    QLineEdit *passwd;
    QPushButton *login;
    QPushButton *changePasswd;
    QPushButton *canc;

    interface_ctrl &ctrl;
//    sys_ctrl ctrl;
};

#endif // DIALOGSYSLOGIN_H
