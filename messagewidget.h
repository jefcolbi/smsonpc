#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QWidget>
#include <QTime>
#include "message.h"

namespace Ui {
class MessageWidget;
}

class MessageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MessageWidget(Message msg,QWidget *parent = 0);
    ~MessageWidget();

    QSize sizeHint() const{return QSize(300,50);}

private:
    Ui::MessageWidget *ui;
};

#endif // MESSAGEWIDGET_H
