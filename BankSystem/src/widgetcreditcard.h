#ifndef WIDGETCREDITCARD_H
#define WIDGETCREDITCARD_H

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "gen/BankSystem.h"
#include <QFormLayout>

class WidgetCreditCard : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetCreditCard(QString idc,QWidget *parent = nullptr);

signals:

public slots:

    //TODO change layout ,display credit etc.

private:
    credit_crtl ctrl;

    QVBoxLayout *layout_main;
    QLineEdit	*le_creditcard_id;
    QPushButton *btn_pay;
    QPushButton	*btn_enchashment;
    QPushButton *btn_showmsg;
    QLabel		*lb_img;

    QFormLayout	*layout_fl;
    QLabel *text1;
    QLabel *text2;
    QLabel *text3;



private:
    void init_ui();
    void init_res();
    QString idcard;
};

#endif // WIDGETCREDITCARD_H
