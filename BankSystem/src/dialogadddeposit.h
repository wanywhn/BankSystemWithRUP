#ifndef DIALOGADDDEPOSIT_H
#define DIALOGADDDEPOSIT_H

#include <QComboBox>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QTabWidget>

#include "gen/App_Layer.h"



class DialogAddDeposit : public QDialog
{
public:
    DialogAddDeposit(one_card_control &c);

private:
    void init_res();
    void init_ui();


private:
    one_card_control &ctrl;
//    QTabWidget *tb_center;
//    QWidget			*fixed;
//    QWidget			*huoqi;
//    QWidget			*dinghuo;


    QLineEdit *le_benjin;
    QComboBox *cb_cunqi;
    QComboBox *cb_money_kind;
    QComboBox *cb_deposit_kind;
    QLabel	  *lb_lilv;
    QRadioButton *rb_autocontinue;

    QPushButton *btn_accept;
    QPushButton *btn_calcen;


private slots:
    void process_btn(int type);


};

#endif // DIALOGADDDEPOSIT_H
