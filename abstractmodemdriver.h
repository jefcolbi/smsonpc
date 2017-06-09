#ifndef ABSTRACTMODEMDRIVER_H
#define ABSTRACTMODEMDRIVER_H
#include <QObject>

#include "contact.h"


class AbstractModemDriver
{
    virtual bool sendSms(QByteArray message="", QByteArray number="")=0;
    virtual bool onReceiveSms()=0;
    virtual bool onReceiveResult()=0;
    virtual void getContacts()=0;
    virtual bool saveContact(QByteArray name="", QByteArray number="")=0;
};

#endif // ABSTRACTMODEMDRIVER_H
