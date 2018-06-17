#ifndef DIALOGPAYCREDITCARD_H
#define DIALOGPAYCREDITCARD_H

#include <QComboBox>
#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "gen/BankSystem.h"



class DialogPayCreditCard : public QDialog
{
    Q_OBJECT
public:
    DialogPayCreditCard(QString idcard,QString sid,QString ocd);

private slots:
    void slots_pay();


private:
    void init_res();
    void init_ui();
    void init_data();


private:
    QFormLayout	*layout_main;
    QComboBox	*cb_creditcard;
    QLabel	*lb_own;
    QLabel	*lb_least;
    QLineEdit	*le_num;
    QPushButton	*btn_accept;
    QPushButton	*btn_calcen;

private:
    QString idcard;
    QString sid;
    QString ocd;
    online_ctrl	octrl;
    credit_crtl cctrl;
};

#endif // DIALOGPAYCREDITCARD_H
