#ifndef OPENACCOUNT_H
#define OPENACCOUNT_H

#include <QDialog>
#include <QObject>
#include <QFormLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>

#include "gen/App_Layer.h"

class OpenAccount : public QDialog
{
public:
    OpenAccount(one_card_control &card_ctrl);


private:
    one_card_control &ctrl;
    QFormLayout *main_layout;

    QPushButton *accept;
    QPushButton *denay;
    QLineEdit *name;
    QLineEdit *idcard;
     QLineEdit *address;
     QLineEdit *phone;
     QLineEdit *passwd;

    void init_res();
    void init_ui();


};

#endif // OPENACCOUNT_H
