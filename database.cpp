#include "database.h"

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("smsonpc.db");
    bool ok = db.open();
    if(!ok)
    {
        qDebug()<< db.lastError();
    }

    QSqlQuery requete;
    ok = requete.exec("CREATE TABLE IF NOT EXISTS Contacts (number VARCHAR(20) NOT NULL UNIQUE, name VARCHAR(50))");
    if(!ok)
    {
        qDebug()<< db.lastError();
    }

    ok = requete.exec("CREATE TABLE IF NOT EXISTS Messages (message TXT, number VARCHAR(20), send BOOLEAN, time DATETIME DEFAULT CURRENT_TIMESTAMP)");
    if(!ok)
    {
        qDebug()<< db.lastError();
    }

    ok = requete.exec("CREATE TABLE IF NOT EXISTS Discussions (number VARCHAR(20), time DATETIME DEFAULT CURRENT_TIMESTAMP)");
    if(!ok)
    {
        qDebug()<< db.lastError();
    }
}

Database::~Database()
{
    db.close();
}
