#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <QtSql>

class Contact
{
public:
    Contact(QString name="", QString number=0);
    bool saveToModem();
    bool saveToPhone();
    bool saveToLocal();

    QString getName(){return name;}
    QString getNumber(){return number;}

    static QList<Contact> getFromDatabase();
    static QList<Contact> getFromPhone();

private:
    QString name, number;
};

#endif // CONTACT_H
