#ifndef DISCUSSION_H
#define DISCUSSION_H

#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>

#include "message.h"

class Discussion
{
public:
    Discussion();
    Discussion(QListWidget *pShortDiscuss, QListWidget *pFullDiscuss, QString pNumber);
    ~Discussion();

    void addMessage(QString msgText, time_t time, bool sended);
    void setShortDiscussList(QListWidget *pShortDiscuss);
    void setFullDiscussList(QListWidget *pFullDiscuss);

    QString getNumber(){return number;}

private:
    QList<Message> msgList;
    QListWidget *discussList;
    QListWidget *fullDiscussList;
    QString number;
};

#endif // DISCUSSION_H
