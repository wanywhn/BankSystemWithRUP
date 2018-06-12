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

                //消费累计
                query.exec("CREATE TABLE credit_consume (id INTEGER PRIMARY KEY,"
                           "FOREIGN KEY (id) REFERENCES credit_card(id) ,"
                           "total FLOAT"//总共的刷卡消费金额，以方便计算最低还款额
                           ")"
                           );
                //信用卡
                query.exec("CREATE TABLE credit_card (id INTEGER PRIMARY KEY,"
                           "interest_free_money FLOAT,credit FLOAT,used FLOAT,paid FLOAT,passwd TEXT)");
                //			  所有可用的额度             总额度       已使用      已还款（不准备做提前还款）

                //消费与支取记录
                query.exec("CREATE TABLE consume_log (id INTEGER PRIMARY KEY AUTOINCREMENT,"
                           "figure FLOAT,reason TEXT,date TEXT,cid INTEGER,"
                           //金额		 花费原因		 日期
                           "FOREIGN KEY (cid) REFERENCES credit_card(id))");
                //支取信息
                query.exec("CREATE TABLE enchashment_tb (id INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "figure FLOAT ,server_charge FLOAT,enchashment_interest FLOAT "
                           //支取金额		预借现金手续费				支取利息
                           " )");


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
                query.exec("CREATE TABLE IF NOT EXISTS lilv (type INTEGER PRIMARY KEY,"
                           "current FLOAT,one_year FLOAT,five_year FLOAT,"
                           //活期			一年			五年
                           "daikuan FLOAT,credit_enchashment_fee FLOAT,"
                           //贷款利率（暂无用） 取现手续费
                           "credit_lixi FLOAT, credit_overdue_fine FLOAT,"
                           //取现利息				罚款利息
                           "usd FLOAT,yen FLOAT,euro,FLOAT)");
                            //美元	日元			欧元


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
