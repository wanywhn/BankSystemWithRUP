#ifndef WIDGETONLINEBANK_H
#define WIDGETONLINEBANK_H

#include <QComboBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSqlQueryModel>
#include <QTableView>
#include <QWidget>

#include "gen/BankSystem.h"

#include "databaseutils.h"

class WidgetOnlineBank : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetOnlineBank(online_ctrl &c,QWidget *parent = nullptr);

signals:

public slots:

    void show_record();
    void slots_transfer();
    void show_analy();
    void slots_loss_report();
    void slots_people();
    void slots_open_creditcard();
    void slots_pay_creditcard();


private:
    QHBoxLayout	*layout_main;
    QVBoxLayout	*layout_rv;
    QVBoxLayout *layout_lv;

    QTableView	*tv_lview;
    QComboBox	*cb_onecard;


    QPushButton	*btn_record;
    QPushButton	*btn_transfer;
    QPushButton	*btn_analy;
    QPushButton *btn_people;
    QPushButton	*btn_open_creditcard;

    QPushButton	*btn_change_passwd;
    QPushButton	*btn_loss_report;

    QPushButton	*btn_pay_creditcard;


    QSqlQueryModel	*sqlmodel;

private:
    void init_res();
    void init_ui();
    void init_data();

private:
    online_ctrl &ctrl;

};

#endif // WIDGETONLINEBANK_H
