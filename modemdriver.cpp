#include "modemdriver.h"

ModemDriver::ModemDriver()
{
    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
    qDebug()<< portList.size();
    QString portName, description;
    port = 0;
    for(int i=0; i<portList.size();i++)
    {
        description = portList[i].description();
        portName = portList[i].portName();
        qDebug()<< portName;
        qDebug()<< description<< "\n";
        if(description == "SCD Control Port")
        {
            port = new QSerialPort(portName);
            port->setBaudRate(QSerialPort::Baud115200);
            port->open(QSerialPort::ReadWrite);
            connect(port,&QSerialPort::readyRead,this,&ModemDriver::onData);
            //connect(port,&QSerialPort::error,this,&ModemDriver::onPortError);
            port->write(QByteArray("AT+CREG=0\r"));
            state = ModemDriver::State::INIT;
            id = 1;
        }
    }
}

ModemDriver::~ModemDriver()
{
    if(port)
    {
        port->close();
        delete port;
    }
}

bool ModemDriver::sendSms(QByteArray message, QByteArray number)
{
    state = ModemDriver::State::SENDSMS;
    if(id==0)
    {
        tmpData = message;
        tmpData2 = number;
        QByteArray toSend("AT+CMGS=");
        toSend.append('"'); toSend.append(number); toSend.append('"'); toSend.append('\r');
        port->write(toSend);
        id = 1;
    }
    else if(id == 1)
    {
        if (data.contains('>'))
        {
            QByteArray toSend(tmpData);
            toSend.append((char)26); toSend.append('\r');
            port->write(toSend);
            id = 2;
        }
        else
        {
            id=0;
            state = ModemDriver::State::READY;
        }
    }
    data.clear();
}

bool ModemDriver::onReceiveSms()
{

}

bool ModemDriver::onReceiveResult()
{

}

void ModemDriver::getContacts()
{
    state = ModemDriver::State::GETCONTACT;
    if(id == 0)
    {
        port->write(QByteArray("AT+CPBR=1,250\r"));
        id = 1;
    }
    else if(id == 1)
    {
        qDebug()<< "We are here";
        QList<QByteArray> ctList;
        QList<Contact> contacts;
        QByteArray tmpLine;
        int pos=0, lon;
        while (1)
        {
            lon = data.indexOf(QByteArray("\r\n\r\n"),pos);
            if(lon == -1)
                break;
            tmpLine = data.mid(pos, lon-pos);
            pos = lon+4;
            ctList.append(tmpLine);
        }
        foreach (QByteArray line, ctList) {
            QByteArray number, name;
            pos = line.indexOf('"',0);
            lon = line.indexOf('"',pos+1);
            number = line.mid(pos+1, lon-pos-1);
            pos = line.indexOf('"',lon+1);
            lon = line.indexOf('"',pos+1);
            name = line.mid(pos+1, lon-pos-1);
            Contact tmpCon(name,number);
            contacts.append(tmpCon);
        }
        if(!contacts.isEmpty())
            emit contactsReceived(contacts);
        id = 0;
        state = ModemDriver::State::READY;
    }
    data.clear();
}

bool ModemDriver::saveContact(QByteArray name, QByteArray number)
{
    state = ModemDriver::State::SAVECONTACT;
    if(id==0)
    {
        tmpData = name;
        tmpData2 = number;
        QByteArray toSend("AT+CPBS=");
        toSend.append('"'); toSend.append("AD"); toSend.append('"'); toSend.append('\r');
        port->write(toSend);
        id = 1;
    }
    else if(id == 1)
    {
        if (data.contains("\r\nOK\r\n"))
        {
            QByteArray toSend("AT+CPBS=");
            toSend.append('"'); toSend.append("123"); toSend.append('"'); toSend.append(',');
            toSend.append('"'); toSend.append(tmpData2); toSend.append('"'); toSend.append(',');
            toSend.append('"'); toSend.append(tmpData); toSend.append('"');

            toSend.append('\r');
            port->write(toSend);
            id = 2;
        }
        else
        {
            id=0;
            state = ModemDriver::State::READY;
        }
    }
    data.clear();
}

bool ModemDriver::init()
{
    if(id == 1)
    {
        if(data.contains(QByteArray("OK")))
        {
            port->write(QByteArray("AT+CGREG=0\r"));
            id = 2;
        }
        else
            id = 0;
    }
    else if(id == 2)
    {
        if(data.contains(QByteArray("OK")))
        {
            port->write(QByteArray("AT+CMGF=1\r"));
            id = 3;
        }
        else
            id = 0;
    }
    else if(id == 3)
    {
        id = 0;
    }
    data.clear();

}

void ModemDriver::onData()
{
    while(port->bytesAvailable())
    {
        data.append(port->readAll());
    }
    if(!data.endsWith(QByteArray("\r\nOK\r\n")))
        return;
    if(state == ModemDriver::State::INIT)
        init();
    else if(state == ModemDriver::State::GETCONTACT)
        getContacts();
}

void ModemDriver::onPortError(QSerialPort::SerialPortError error)
{

}
