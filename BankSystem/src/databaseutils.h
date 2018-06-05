#ifndef DATABASEUTILS_H
#define DATABASEUTILS_H

#include <QSqlDatabase>

class DataBaseUtils
{
public:
    static QSqlDatabase getInstance();

private:
    DataBaseUtils();
    static QSqlDatabase db;
};

#endif // DATABASEUTILS_H
