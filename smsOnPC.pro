#-------------------------------------------------
#
# Project created by QtCreator 2017-03-29T12:30:37
#
#-------------------------------------------------

QT       += core gui sql serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = smsOnPC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    contactitem.cpp \
    message.cpp \
    discussion.cpp \
    emojidialog.cpp \
    contact.cpp \
    database.cpp \
    modemdriver.cpp \
    emojiform.cpp \
    messagewidget.cpp

HEADERS  += mainwindow.h \
    contactitem.h \
    message.h \
    discussion.h \
    emojidialog.h \
    abstractmodemdriver.h \
    contact.h \
    database.h \
    modemdriver.h \
    emojiform.h \
    messagewidget.h

FORMS    += mainwindow.ui \
    emojidialog.ui \
    emojiform.ui \
    messagewidget.ui

RESOURCES += \
    ressources.qrc

CONFIG += resources_big
