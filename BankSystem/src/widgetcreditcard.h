#ifndef WIDGETCREDITCARD_H
#define WIDGETCREDITCARD_H

#include <QWidget>
#include "gen/BankSystem.h"

class WidgetCreditCard : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetCreditCard(QWidget *parent = nullptr);

signals:

public slots:


private:
    credit_ctrl ctrl;
};

#endif // WIDGETCREDITCARD_H
