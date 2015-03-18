#-------------------------------------------------
#
# Project created by QtCreator 2015-03-18T08:53:41
#
#-------------------------------------------------

QT       += core concurrent

QT       -= gui

TARGET = iteratortest
CONFIG   += console c++11
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -O

SOURCES += main.cpp \
    mylist.cpp

HEADERS += \
    mylist.h
