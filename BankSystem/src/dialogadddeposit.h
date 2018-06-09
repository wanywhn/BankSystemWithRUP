#ifndef DIALOGADDDEPOSIT_H
#define DIALOGADDDEPOSIT_H

#include <QDialog>
#include <QLineEdit>
#include <QRadioButton>
#include <QTabWidget>



class DialogAddDeposit : public QDialog
{
public:
    DialogAddDeposit();

private:
    void init_res();
    void init_ui();


private:
    QTabWidget *tb_center;
    QWidget			*fixed;
    QWidget			*huoqi;
    QWidget			*dinghuo;


    QLineEdit *le_benjin;
    QLineEdit *le_cunqi;
    QLineEdit *le_lilv;
    QRadioButton *rb_autocontinue;

};

#endif // DIALOGADDDEPOSIT_H
