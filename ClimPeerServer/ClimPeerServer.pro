#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T14:59:14
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClimPeerServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    chatdialog.cpp \
    client.cpp \
    connection.cpp \
    peermanager.cpp \
    server.cpp

HEADERS  += mainwindow.h\
            chatdialog.h \
    client.h \
    connection.h \
    peermanager.h \
    server.h

FORMS    += mainwindow.ui \
    chatdialog.ui
