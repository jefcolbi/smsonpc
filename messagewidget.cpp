#include "messagewidget.h"
#include "ui_messagewidget.h"

MessageWidget::MessageWidget(Message msg,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageWidget)
{
    ui->setupUi(this);
    ui->lblMsg->setText(msg.getText());
    ui->lblHour->setText(QTime::currentTime().toString("H:m"));
}

MessageWidget::~MessageWidget()
{
    delete ui;
}
