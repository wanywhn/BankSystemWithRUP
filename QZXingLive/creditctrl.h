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
 static   void log(QString reason, int count, QString id, QString cid,QString type);
};

class credit_crtl{
public:
    credit_crtl(QString id);


public:
    QPair<bool,QString> pay(QString credit_id,float value,QString reason,QString type);
private:
    bool checkifexists(QString id);
    bool checkifenough(float value,QString credit_id);
    QString id_card;
};


#endif // CREDITCTRL_H
