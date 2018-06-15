#ifndef DIALOGTRANSFER_H
#define DIALOGTRANSFER_H

#include <QDialog>
#include <QFormLayout>
#include <QComboBox>

#include "gen/App_Layer.h"

#include "gen/BankSystem.h"



class DialogTransfer : public QDialog
{
public:
    DialogTransfer(QString ocd,QString subaccount);

private:
    void init_res();
    void init_ui();
    void init_data();
    QPair<bool,QString> store_familiar(QString name,QString ocd);

private:
    one_card_control ctrl;

    QFormLayout	*layout_fl;
    QComboBox	*cb_name;
    QComboBox	*cb_onecard;
    QLineEdit	*le_count;
    QPushButton	*btn_accept;
    QPushButton	*btn_cancel;

    QMultiMap<QString,QString> map;

    bool new_name;
    QString idcard;
    QString saccount;
    QString ocd;

private slots:
    void slots_name_changed(QString name);
    void slots_onecard_changed(QString ocd);
    void slots_transfer_money();


};

#endif // DIALOGTRANSFER_H
