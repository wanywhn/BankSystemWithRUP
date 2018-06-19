#include "databaseutils.h"
#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <QDebug>
static bool init_db(){
    auto db=DataBaseUtils::getInstance();
    if(!db.open()){

        qDebug()<<db.lastError();
        return false;
    }
    QSqlQuery query(db);
                //TODO init table

                query.exec("CREATE TABLE IF NOT EXISTS id_card (iid VARCHAR(20) PRIMARY KEY ,online_bank boolean DEFAULT '0',online_name TEXT ,"
                           " passwd TEXT )");
                //信用卡
                query.exec("CREATE TABLE IF NOT EXISTS credit_card (id INTEGER PRIMARY KEY  AUTO_INCREMENT ,"
                           "interest_free_money FLOAT DEFAULT 0,credit FLOAT,used FLOAT DEFAULT 0,paid FLOAT DEFAULT 0,passwd TEXT,cid VARCHAR(20),"
                           "FOREIGN KEY (cid) REFERENCES id_card(iid) ) ENGINE = InnoDB AUTO_INCREMENT = 2000000000");
                //			  所有可用的额度             总额度       已使用      已还款（不准备做提前还款）

                qDebug()<<query.lastError();
                //消费累计
                query.exec("CREATE TABLE IF NOT EXISTS credit_consume (id INTEGER PRIMARY KEY,"
                           "FOREIGN KEY (id) REFERENCES credit_card(id) ,"
                           "total FLOAT"//总共的刷卡消费金额，以方便计算最低还款额
                           ")"
                           );

                qDebug()<<query.lastError();



                //支取信息
                query.exec("CREATE TABLE IF NOT EXISTS enchashment_tb (id INTEGER PRIMARY KEY AUTO_INCREMENT,"
                            "figure FLOAT ,server_charge FLOAT,enchashment_interest FLOAT, credit_id INTEGER,"
                           "FOREIGN KEY (credit_id) REFERENCES credit_card(id)  "
                           //支取金额		预借现金手续费				支取利息
                           " )");


                query.exec("CREATE TABLE IF NOT EXISTS sys_acc_tb (id INTEGER PRIMARY KEY ,"
                           "passwd TEXT,admin boolean DEFAULT '0') ");


                //消费与支取记录
                query.exec("CREATE TABLE IF NOT EXISTS consume_log (id INTEGER PRIMARY KEY AUTO_INCREMENT,"
                           "figure FLOAT,reason TEXT,date TEXT,cid VARCHAR(20),cardid INTEGER ,type TEXT ,"
                           //金额		 花费原因		 日期		idcard  		 the id of card
                           "FOREIGN KEY (cid) REFERENCES id_card(iid))");

                qDebug()<<query.lastError();

                qDebug()<<query.lastError();
                query.exec("CREATE TABLE IF NOT EXISTS one_card (id INTEGER AUTO_INCREMENT,"
                           " owner_name varchar(20),idcard VARCHAR(20),"
                          " address varchar(20), phone_number varchar(12),passwd varchar(16),"
                          " lost boolean DEFAULT '0',lost_time TEXT ,auto_continue boolean DEFAULT '0',"
                          " FOREIGN KEY(idcard) REFERENCES id_card(iid),"
                           "PRIMARY KEY(id,owner_name) )");

                qDebug()<<query.lastError();

                query.exec("CREATE TABLE IF NOT EXISTS familiar (onecard INTEGER,name VARCHAR(20),idcard VARCHAR(20),PRIMARY KEY(onecard,name,idcard),"
                           "FOREIGN KEY(onecard) REFERENCES one_card(id),"
                           "FOREIGN KEY(idcard) REFERENCES id_card(iid) )");

                qDebug()<<query.lastError();
                query.exec("CREATE TABLE IF NOT EXISTS saving_subaccount(id INTEGER , s_type INTEGER , benjin DOUBLE,nianxian INTEGER,lilv float,qishi_shijian DATE ,ac bool,lixi float,m_type INTEGER,cid INTEGER ,FOREIGN KEY (cid) REFERENCES one_card(id) ,PRIMARY KEY(id,cid))");
                qDebug()<<query.lastError();

                query.exec("CREATE TABLE IF NOT EXISTS lilv (id INTEGER PRIMARY KEY AUTO_INCREMENT,"
                           "current FLOAT,one_year FLOAT,five_year FLOAT,"
                           //活期			一年			五年
                           "daikuan FLOAT,credit_enchashment_fee FLOAT,"
                           //贷款利率（暂无用） 取现手续费
                           "credit_lixi FLOAT, credit_overdue_fine FLOAT,"
                           //取现利息				罚款利息
                           "usd FLOAT,yen FLOAT,euro FLOAT)");
                            //美元	日元			欧元



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
