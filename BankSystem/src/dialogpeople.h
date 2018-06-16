#ifndef DIALOGPEOPLE_H
#define DIALOGPEOPLE_H

#include <QDialog>
#include <QHBoxLayout>
#include <QSqlTableModel>
#include <QTableView>



class DIalogPeople : public QDialog
{
    Q_OBJECT
public:
    DIalogPeople(QString id);


private:
    QHBoxLayout	*layout_main;
    QTableView	*tv_disp;
    QSqlTableModel	*sqlmodel;

    QVBoxLayout	*layout_rv;
    QPushButton *btn_add;
    QPushButton	*btn_delete;


    QString idcard;

private:
    void init_res();
    void init_ui();
    void init_data();
};

#endif // DIALOGPEOPLE_H
