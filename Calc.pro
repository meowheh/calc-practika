#-------------------------------------------------
#
# Project created by QtCreator 2020-06-30T17:10:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculate.cpp \
    enteredexception.cpp

HEADERS  += mainwindow.h \
    calculate.h \
    enteredexception.h

FORMS    += mainwindow.ui
