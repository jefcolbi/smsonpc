#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    //ui->emoList->hide();
    md = new ModemDriver();
    this->setupSignals();
    firstShow = false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete md;
}

void MainWindow::setupSignals()
{
    connect(ui->tEdit_message, &QTextEdit::textChanged, this, &MainWindow::addTask);
    connect(ui->textButton, &QPushButton::clicked, this, &MainWindow::addDiscussion);
    connect(ui->tBtn_emoji,&QPushButton::clicked,this,&MainWindow::showEmoji);
    connect(ui->psbGetContact,&QPushButton::clicked,this,&MainWindow::getContacts);
    connect(md,&ModemDriver::contactsReceived,this,&MainWindow::onGetContacts);
    connect(ui->psbAddMsg,&QPushButton::clicked,this,&MainWindow::displayMessage);
}

void MainWindow::addTask()
{
    qDebug() << "on appele";
}

void MainWindow::addDiscussion()
{
    QString text = this->ui->lneNumber->text();
    Discussion ds = Discussion(this->ui->listWidget, NULL, text);
    discussList.append(ds);
}

void MainWindow::showEmoji()
{
    /*ui->emoList->show();
    int i=0;
    foreach( const QString &imageName, QDir(":emojis/Graphics/Emojis/png_512x512").entryList() )
    {
        qDebug()<< imageName;
        QListWidgetItem *item = new QListWidgetItem(QIcon(":emojis/Graphics/Emojis/png_512x512/"+imageName),"");
        ui->emoList->insertItem(ui->emoList->currentRow(),item);
        if(++i>50)
            break;
    }*/
}

void MainWindow::onGetContacts(QList<Contact> &contacts)
{
    foreach(Contact ct,contacts)
    {
        Discussion ds = Discussion(this->ui->listWidget, NULL, ct.getName());
        //ct.saveToLocal();
    }
}

void MainWindow::getContacts()
{
    md->getContacts();
}

void MainWindow::loadAll()
{

}

void MainWindow::showEvent(QShowEvent *ev)
{
    if(!firstShow)
    {
        QList<Contact> ctList = Contact::getFromDatabase();
         onGetContacts(ctList);
         firstShow = true;
    }
    QMainWindow::showEvent(ev);
}

void MainWindow::displayMessage()
{
    qDebug()<< "Called";
    Message msg("wandaful",0);
    MessageWidget* msgWid = new MessageWidget(msg);
    ui->discussLayout->addWidget(msgWid);
    //msgWid->show();
    /*msgWid->setGeometry(50,50,0,0);
    ui->frame_2->hide();
    ui->frame_2->show();*/
    //delete msgWid;
}
