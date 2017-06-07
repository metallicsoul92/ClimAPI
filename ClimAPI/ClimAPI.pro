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

 CONFIG += c++17

SOURCES +=src/base/file.cpp \
          main.cpp \
    src/base/logger.cpp \
    src/base/bytearray.cpp \
    src/base/observable.cpp \
    src/base/signal.cpp \
    src/base/slot.cpp \
    src/base/sigslotconnection.cpp

HEADERS += \
    include/math/matrix.hpp \
    include/math/vector.hpp \
    include/base/Array.hpp \
    include/base/metastruct.hpp \
    include/base/hashvalue.hpp \
    include/base/hashmap.hpp \
    include/base/node.hpp \
    include/base/base.hpp \
    include/math/math.hpp \
    include/base/linkedList.hpp \
    include/base/singleton.hpp \
    include/base/ref.hpp \
    include/base/file.hpp \
    include/base/Pair.hpp \
    include/base/logger.hpp \
    include/base/ByteArray.hpp \
    include/base/hex.hpp \
    include/base/octal.hpp \
    include/base/variant.hpp \
    include/base/observable.h \
    include/base/sigslotconnection.h \
    include/base/signal.hpp \
    include/base/slot.hpp
