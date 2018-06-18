#ifndef SYSTEMWIDGET_H
#define SYSTEMWIDGET_H

#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QStringListModel>

#include "gen/BankSystem.h"

class SystemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SystemWidget(QWidget *parent = nullptr);

signals:

public slots:

private slots:
    void update_data(bool given=false, QList<float> list={});
    void reset_date();
    void user_add();
    void user_delete();
    void plan_add();
    void plan_delete();


private:
    void init_ui();
    void init_res();
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
    QLineEdit	*le_daikuan_lilv;


    QGroupBox *gb_credit_card;
    QFormLayout *fl_credit_card;
    QLineEdit	*le_credit_interest;
    QLineEdit	*le_credit_enchashment_fee;
    QLineEdit	*le_credit_overdue_fine;

    QGroupBox *gb_user_manage;
    QFormLayout	*fl_user;
    QComboBox	*cb_cate;
    QCheckBox	*cb_sys;
    QPushButton	*btn_add_user;
    QPushButton	*btn_delete_user;
    QPushButton	*btn_modify_user;

    QGroupBox *gb_plan;
    QVBoxLayout *layout_plan;
    QListView *lv_plan;
    QLabel	*lb_started;
    QDateTimeEdit	*de_time;
    QPushButton *btn_plan_add;
    QPushButton *btn_plan_delete;


    QStringListModel	*lm_model;


    QPushButton *btn_accept;
    QPushButton *btn_reset;

    QTimer timer;
    QTimer timer_aux;

};

#endif // SYSTEMWIDGET_H
