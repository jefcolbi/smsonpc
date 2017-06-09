#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include <QDebug>

class Database
{
public:
    Database();
    ~Database();

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
