#include "contact.h"

Contact::Contact(QString name, QString number)
{
    this->name = name;
    this->number = number;
}

bool Contact::saveToLocal()
{
    QSqlQuery requete;
    requete.prepare("INSERT INTO Contacts (number,name) VALUES (:number,:name)");
    requete.bindValue(":number",number);
    requete.bindValue(":name",name);
    bool ok = requete.exec();
    if(!ok)
    {
        qDebug()<< requete.lastError();
    }
}

QList<Contact> Contact::getFromDatabase()
{
    QList<Contact> contacts = QList<Contact>();
    QSqlQuery requete;
    bool ok = requete.exec("SELECT name,number FROM Contacts");
    if(!ok)
    {
        qDebug()<< requete.lastError();
        return contacts;
    }
    while(requete.next())
    {
        contacts.append(Contact(requete.value(0).toString(),requete.value(1).toString()));
    }
    return contacts;
}
