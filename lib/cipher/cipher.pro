#-------------------------------------------------
#
# Project created by QtCreator 2016-03-02T14:16:52
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = cipher
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


HEADERS += aes.h \
    rc4.h \
    salsa20.h

SOURCES += main.cpp \
            aes.cpp \
    rc4.cpp \
    salsa20.cpp
