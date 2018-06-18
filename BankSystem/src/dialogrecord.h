#ifndef DIALOGRECORD_H
#define DIALOGRECORD_H

#include <QComboBox>
#include <QDateEdit>
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
    QString id_card;
    QStringList	type_list;


    QVBoxLayout	*layout_main;

    QFormLayout	*layout_fl;

    QComboBox	*cb_categ;
    QTableView	*tv_sqlview;
    QSqlQueryModel	*sqlmodel;


private:
    void init_data();
    void init_ui();
    void init_res();


private slots:
    void slots_categ_changed(const QString &str);

};

#endif // DIALOGRECORD_H
