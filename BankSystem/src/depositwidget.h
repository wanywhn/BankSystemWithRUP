#ifndef DEPOSITWIDGET_H
#define DEPOSITWIDGET_H

#include <QSql>
#include <QComboBox>
#include <QPushButton>
#include <QTableView>
#include <QWidget>

class DepositWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DepositWidget(QWidget *parent = nullptr);

signals:

public slots:


private:
    QTableView *sqlView;
    QComboBox *category_combobox;

    QPushButton *add_subaccount;
    QPushButton *delete_subaccount;

    QPushButton *add_deposit;
    QPushButton *withdraw_money;

private:
    void init_ui();
    void init_res();

};

#endif // DEPOSITWIDGET_H
