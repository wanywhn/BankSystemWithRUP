#ifndef WIDGETONLINEBANK_H
#define WIDGETONLINEBANK_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QSqlQueryModel>
#include <QTableView>
#include <QWidget>

#include "databaseutils.h"

class WidgetOnlineBank : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetOnlineBank(QWidget *parent = nullptr);

signals:

public slots:



private:
    QHBoxLayout	*layout_main;
    QVBoxLayout	*layout_rv;

    QTableView	*tv_lview;
    QPushButton	*btn_record;
    QPushButton	*btn_transfer;
    QPushButton	*btn_analy;

    QPushButton	*btn_change_passwd;
    QPushButton	*btn_loss_report;


    QSqlQueryModel	*sqlmodel;

private:
    void init_res();
    void init_ui();

};

#endif // WIDGETONLINEBANK_H
