#ifndef SYSTEMWIDGET_H
#define SYSTEMWIDGET_H

#include <QWidget>

#include "gen/BankSystem.h"

class SystemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SystemWidget(QWidget *parent = nullptr);

signals:

public slots:



private:
    sys_ctrl ctrl;
};

#endif // SYSTEMWIDGET_H
