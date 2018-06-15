#ifndef WIDGETCREDITCARD_H
#define WIDGETCREDITCARD_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "gen/BankSystem.h"

class WidgetCreditCard : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetCreditCard(QString idc,QWidget *parent = nullptr);

signals:

public slots:


private:
    credit_crtl ctrl;

    QVBoxLayout *layout_main;
    QLineEdit	*le_creditcard_id;
    QPushButton *btn_pay;
    QPushButton *btn_enchashment;

private:
    void init_ui();
    void init_res();
    QString idcard;
};

#endif // WIDGETCREDITCARD_H
