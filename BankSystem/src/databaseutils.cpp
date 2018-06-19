#include "databaseutils.h"
#include <QDebug>
//QString connection_name="qt_sql_default_connection";
QString connection_name="jiaqingtong";

QSqlDatabase DataBaseUtils::getInstance()
{

    if(QSqlDatabase::contains(connection_name)){
        db=QSqlDatabase::database(connection_name);
        db.setDatabaseName(connection_name);
    }else{
    db=QSqlDatabase::addDatabase("QMYSQL",connection_name);
    db.setDatabaseName(connection_name);
    }
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("Wanywhn11");
   return db;

}

DataBaseUtils::DataBaseUtils()
{

}
 QSqlDatabase DataBaseUtils::db;
