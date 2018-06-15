#ifndef DIALOGRECORD_H
#define DIALOGRECORD_H

#include <QComboBox>
#include <QDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QSqlQueryModel>
#include <QTableView>



class DialogRecord : public QDialog
{
    Q_OBJECT
public:
    DialogRecord(QString ocd);
    virtual ~DialogRecord(){}

private:
    QString one_card;
    QStringList	type_list;


    QVBoxLayout	*layout_main;

    QFormLayout	*layout_fl;

    QPushButton	*btn_select_date;
    QComboBox	*cb_categ;
    QPushButton	*btn_refersh;
    QTableView	*tv_sqlview;
    QSqlQueryModel	*sqlmodel;


private:
    void init_data();
    void init_ui();
    void init_res();


private slots:
    void slots_select_date();
    void slots_refersh();

};

#endif // DIALOGRECORD_H
