#-------------------------------------------------
#
# Project created by QtCreator 2016-11-28T19:04:54
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ClimAPI
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

 CONFIG += c++11

SOURCES += main.cpp

HEADERS += \
    include/math/matrix.hpp \
    include/math/vector.hpp \
    include/base/Array.hpp \
    include/base/bivar.hpp \
    include/base/metastruct.hpp
