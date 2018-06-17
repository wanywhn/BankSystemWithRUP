#ifndef CREDITCTRL_H
#define CREDITCTRL_H

#include <QObject>

class CreditCtrl : public QObject
{
    Q_OBJECT
public:
    explicit CreditCtrl(QObject *parent = nullptr);

signals:

public slots:

public :
    Q_INVOKABLE void pay(QString creditid,int value,QString type);
};

#endif // CREDITCTRL_H
