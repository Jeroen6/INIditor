# INIditor (Automatic graphical editor for ini file)
# Copyright (C) 2014  Jeroen Lodder
#
#-------------------------------------------------
#
# Project created by QtCreator 2014-08-18T19:09:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = INIditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    inisection.cpp \
    inikey.cpp

HEADERS  += mainwindow.h \
    inisection.h \
    inikey.h

FORMS    += mainwindow.ui

RC_FILE = icon.rc

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    icon.rc

DISTFILES += \
    ../test/test.ini
