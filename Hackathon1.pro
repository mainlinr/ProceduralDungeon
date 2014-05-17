#-------------------------------------------------
#
# Project created by QtCreator 2014-05-09T19:47:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hackathon1
TEMPLATE = app

INCLUDEPATH += D:\boost_1_55_0\

SOURCES += main.cpp\
        mainwindow.cpp \
    floorcontainer.cpp

HEADERS  += mainwindow.h \
    floorcontainer.h \
    dungeonenums.h

FORMS    += mainwindow.ui

RESOURCES += \
    DungeonResources.qrc
