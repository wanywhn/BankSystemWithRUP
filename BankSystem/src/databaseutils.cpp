#include "databaseutils.h"
#include <QDebug>
QString connection_name="qt_sql_default_connection";

QSqlDatabase DataBaseUtils::getInstance()
{

    if(QSqlDatabase::contains(connection_name)){
        db=QSqlDatabase::database(connection_name);
        db.setDatabaseName(connection_name);
    }else{
    db=QSqlDatabase::addDatabase("QMYSQL",connection_name);
    db.setDatabaseName(connection_name);
    }
    db.setHostName("ericsuens.xin");
    db.setUserName("root");
    db.setPassword("sunyukang123");
   return db;

}

DataBaseUtils::DataBaseUtils()
{

}
 QSqlDatabase DataBaseUtils::db;
