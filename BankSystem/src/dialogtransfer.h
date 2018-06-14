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
    DialogTransfer(QString ocd);

private:
    void init_res();
    void init_ui();
    void init_data();

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

private slots:
    void slots_name_changed(QString name);
    void slots_onecard_changed(QString ocd);


};

#endif // DIALOGTRANSFER_H
