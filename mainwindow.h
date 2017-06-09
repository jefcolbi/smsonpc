#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDir>

#include "discussion.h"
#include "contact.h"
#include "modemdriver.h"
#include "messagewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addTask();
    void addDiscussion();
    void showEmoji();
    void onGetContacts(QList<Contact>& contacts);
    void getContacts();
    void showEvent(QShowEvent *ev);
    void displayMessage();

private:
    Ui::MainWindow *ui;
    ModemDriver *md;
    QList<Discussion> discussList;
    bool firstShow;

    void loadAll();
    void setupSignals();
};

#endif // MAINWINDOW_H
