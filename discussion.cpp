#include "discussion.h"

Discussion::Discussion()
{
    discussList = NULL;
    fullDiscussList = NULL;
    msgList = QList<Message>();
}

Discussion::Discussion(QListWidget *pShortDiscuss, QListWidget *pFullDiscuss, QString pNumber)
{
    discussList = pShortDiscuss;
    fullDiscussList = pFullDiscuss;
    msgList = QList<Message>();
    number = pNumber;

    QListWidgetItem *item = new QListWidgetItem(QIcon(":/icones/Graphics/Icons/dummy-user-img.png"), number);
    item->setTextAlignment(Qt::AlignCenter|Qt::AlignVCenter);
    item->setFont(QFont("SegoeUi",12,-1,true));
    discussList->insertItem(0, item);
}

Discussion::~Discussion()
{
    msgList.clear();
    discussList = NULL;
    fullDiscussList = NULL;
}

void Discussion::addMessage(QString msgText, time_t time, bool sended)
{
    Message msg = Message(msgText, time, sended);
    msgList.append(msg);
}
