#include "databaseutils.h"
#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <QDebug>
static bool init_db(){
    auto db=DataBaseUtils::getInstance();
    if(!db.open())
        return false;
    QSqlQuery query(db);
    QString check_table=
            "SELECT COUNT(*) FROM sqlite_master where type='table' and name='user'";

    query.prepare(check_table);
    if(!query.exec()){
        qDebug()<<"init_db"<<query.lastError();
        return  false;
    }else{
    //TODO 添加系统管理用户。

    return true;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!init_db()){
        return 0;
    }
    MainWindow w;
    w.show();


    return a.exec();
}
