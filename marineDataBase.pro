#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T13:29:35
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = marineDataBase
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    additemdialog.cpp \
    item.cpp

HEADERS  += mainwindow.h \
    database.h \
    additemdialog.h \
    item.h

FORMS    += mainwindow.ui \
    additemdialog.ui

QMAKE_CXXFLAGS += -std=gnu++14

RESOURCES += \
    res.qrc
