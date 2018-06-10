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
//    QString check_table=
//            "SELECT COUNT(*) FROM sqlite_master where type='table' and name='one_card'";
            "SHOW TABLES LIKE 'one_card'";

//    query.prepare(check_table);
//    if(!query.exec()){
//        qDebug()<<"init_db"<<query.lastError();
//        return  false;
//    }else{
//        if(query.next()){
//            if(query.value(0).toInt()==0){
//            if(query.size()==0){
                //TODO init table
                query.exec("CREATE TABLE IF NOT EXISTS credit_card (id INTEGER PRIMARY KEY,"
                           "credit INTEGER,used INTEGER,paid INTEGER,"
                           "passwd TEXT,interest_free_money INTEGER,server_charge FLOAT,least_unpaid FLOAT,interest FLOAT,overdue_fine FLOAT)");
                qDebug()<<query.lastError();
                query.exec("CREATE TABLE IF NOT EXISTS consume_tb (id INTEGER PRIMARY KEY AUTOINCREMENT,"
                           "figure FLOAT,reason TEXT,date TEXT)");
                query.exec("CREATE TABLE IF NOT EXISTS enchashment_tb (id INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "figure FLOAT )");


                query.exec("CREATE TABLE IF NOT EXISTS sys_acc_tb (id INTEGER PRIMARY KEY ,"
                           "passwd TEXT,admin boolean DEFAULT 'FALSE'");


                query.exec("CREATE TABLE IF NOT EXISTS saving_subaccount(id INTEGER PRIMARY KEY , s_type INTEGER , benjin DOUBLE,nianxian INTEGER,lilv float,qishi_shijian DATE ,ac bool,lixi float)");

                query.exec("CREATE TABLE IF NOT EXISTS id_card (iid INTEGER ,online_bank boolean DEFAULT 'FALSE',online_name TEXT DEFAULT ' ',"
                           " oneline_passwd TEXT DEFAULT ' ')");
                query.exec("CREATE TABLE IF NOT EXISTS one_card (id INTEGER PRIMARY KEY AUTOINCREMENT,"
                           " owner_name varchar(20),idcard INTEGER ,"
                          " address varchar(20), phone_number varchar(12),passwd varchar(16),"
                          " lost boolean DEFAULT 'FALSE',lost_time TEXT DEFAULT ' ',auto_continue boolean DEFAULT ' ',"
                          " FOREIGN KEY(idcard) REFERENCES id_card(iid) )");

                query.exec("CREATE TABLE IF NOT EXISTS card_saving( cid INTEGER,sid INTEGER,"
                          " FOREIGN KEY(cid) REFERENCES one_card(id),"
                          " FOREIGN KEY(sid) REFERENCES saving_subaccount(id) )");
                query.exec("CREATE TABLE IF NOT EXISTS lilv (type INTEGER PRIMARY KEY,d float)");


//                query.exec("delete from sqlite_sequence where name='one_card'");
//                query.exec("update sqlite_sequence SET seq = 1000000000 where name = 'one_card'");

//            }else{
//                qDebug()<<"have inited";
//            }
//        }else{
//            qDebug()<<"query table error";
//        }

        db.close();

    return true;
//    }
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
