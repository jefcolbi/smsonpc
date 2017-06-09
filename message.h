#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QWidget>

class Message
{
public:
    Message();
    Message(QString text, time_t time, bool sended=false);
    QString getText(){return text;}
    time_t getTime(){return time;}
    bool getSended(){return sended;}

private:
    QString text;
    time_t time;
    bool sended;
};

#endif // MESSAGE_H
