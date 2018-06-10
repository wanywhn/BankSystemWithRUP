#ifndef DEPOSITWIDGET_H
#define DEPOSITWIDGET_H

#include <QSql>
#include <QComboBox>
#include <QPushButton>
#include <QTableView>
#include <QWidget>
#include <QSqlQueryModel>

#include "gen/App_Layer.h"

class DepositWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DepositWidget(one_card_control &ctrl,QWidget *parent = nullptr);

signals:

public slots:


private:
    QTableView *sqlView;
//    QComboBox *category_combobox;

//    QPushButton *add_subaccount;
//    QPushButton *delete_subaccount;

    QPushButton *add_deposit;
    QPushButton *withdraw_money;
    QSqlQueryModel *model;
    QString query_stmt;

private:
    void init_ui();
    void init_res();
    one_card_control &ctrl;

};

#endif // DEPOSITWIDGET_H
