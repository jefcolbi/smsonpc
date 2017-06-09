#ifndef MODEMDRIVER_H
#define MODEMDRIVER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

#include "abstractmodemdriver.h"

class ModemDriver : public QObject, public AbstractModemDriver
{
    Q_OBJECT

    enum State
    {
        INIT,SENDSMS,GETCONTACT,READY,SAVECONTACT
    };

public:
    ModemDriver();
    ~ModemDriver();
    bool sendSms(QByteArray message="", QByteArray number="");
    bool onReceiveSms();
    bool onReceiveResult();
    void getContacts();
    bool saveContact(QByteArray name="", QByteArray number="");
    bool init();

private slots:
    void onData();
    void onPortError(QSerialPort::SerialPortError error);

private:
    QSerialPort *port;
    ModemDriver::State state;
    QByteArray tmpData, tmpData2;
    int id;
    QByteArray data;

signals:
    contactsReceived(QList<Contact> &contacts);
};

#endif // MODEMDRIVER_H
