#ifndef SYSTEMWIDGET_H
#define SYSTEMWIDGET_H

#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "gen/BankSystem.h"

class SystemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SystemWidget(QWidget *parent = nullptr);

signals:

public slots:

private slots:
    void update_data();
    void reset_date();


private:
    void init_ui();
    void init_res();
    void init_data();
private:
    sys_ctrl ctrl;
    QGridLayout *layout_main;

    QGroupBox *gb_deposit;
    QFormLayout *fl_deposit;
    QLineEdit 	*le_deposit_current;
    QLineEdit	*le_deposit_one_year;
    QLineEdit	*le_deposit_five_year;



    QGroupBox *gb_waihui;
    QFormLayout *fl_waihui;
    QLineEdit	*le_waihui_usd;
    QLineEdit	*le_waihui_euro;
    QLineEdit	*le_waihui_yen;



    QGroupBox *gb_daikuan;
    QFormLayout *fl_daikuan;


    QGroupBox *gb_credit_card;
    QFormLayout *fl_credit_card;
    QLineEdit	*le_credit_interest;
    QLineEdit	*le_credit_enchashment_fee;




    QPushButton *btn_accept;
    QPushButton *btn_reset;


};

#endif // SYSTEMWIDGET_H
