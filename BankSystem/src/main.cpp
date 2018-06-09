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
            "SELECT COUNT(*) FROM sqlite_master where type='table' and name='one_card'";

    query.prepare(check_table);
    if(!query.exec()){
        qDebug()<<"init_db"<<query.lastError();
        return  false;
    }else{
        if(query.next()){
            if(query.value(0).toInt()==0){
                //TODO init table
                query.exec("CREATE TABLE saving_subaccount(id INTEGER PRIMARY KEY , s_type INTEGER , benjin INTEGER ,nianxian INTEGER,lilv float,qishi_shijian DATE ,ac bool,lixi float)");

                query.exec("CREATE TABLE one_card (id INTEGER PRIMARY KEY"
                          " AUTOINCREMENT,owner_name varchar(20),id_card varchar(19),"
                          " address varchar(20), phone_number varchar(12),passwd varchar(16),"
                          " online_bank boolean DEFAULT 'FALSE' ,online_name varchar(17) DEFAULT ' ',"
                          " online_passwd varchar(17) DEFAULT ' ',lost boolean DEFAULT 'FALSE',lost_time TEXT DEFAULT ' ',auto_continue boolean DEFAULT ' ')");

                query.exec("CREATE TABLE card_saving( cid INTEGER,sid INTEGER,"
                          " FOREIGN KEY(cid) REFERENCES one_card(id),"
                          " FOREIGN KEY(sid) REFERENCES saving_subaccount(id) )");
                query.exec("CREATE TABLE lilv (type INTEGER PRIMARY KEY,d float)");

                query.exec("delete from sqlite_sequence where name='one_card'");
                query.exec("update sqlite_sequence SET seq = 1000000000 where name = 'one_card'");

            }else{
                qDebug()<<"have inited";
            }
        }else{
            qDebug()<<"query table error";
        }

        db.close();

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
