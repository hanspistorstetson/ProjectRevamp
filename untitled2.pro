#-------------------------------------------------
#
# Project created by QtCreator 2017-04-12T14:08:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    sqlite3.c \
    database/activity.cpp \
    database/dbtest.cpp \
    database/event.cpp \
    database/user.cpp \
    database/sqlite3.c \
    database/checkin.cpp

HEADERS  += mainwindow.h \
    activity.h \
    checkin.h \
    event.h \
    #activity.h#
    database/activity.h \
    database/checkin.h \
    database/event.h \
    database/sqlite3.h \
    database/user.h

FORMS    += mainwindow.ui

DISTFILES += \
    README.txt \
    test.db \
    untitled2.pro.user
