#ifndef DATABASEUTILS_H
#define DATABASEUTILS_H

#include <QSqlDatabase>

extern QString connection_name;
class DataBaseUtils
{
public:
    static QSqlDatabase getInstance();

private:
    DataBaseUtils();
    static QSqlDatabase db;
};

#endif // DATABASEUTILS_H
