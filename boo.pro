#-------------------------------------------------
#
# Project created by QtCreator 2017-04-16T19:40:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = boo
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
    eventcreatewindow.cpp \
    eventadminwindow.cpp \
    usercreatewindow.cpp \
    activitycreatewindow.cpp \
    listactivities.cpp \
    activitysearch.cpp \
    activity.cpp \
    checkin.cpp \
    qrcodefound.cpp \
    qrnotfound.cpp

HEADERS  += mainwindow.h \
    eventcreatewindow.h \
    eventadminwindow.h \
    usercreatewindow.h \
    activitycreatewindow.h \
    listactivities.h \
    activitysearch.h \
    activity.h \
    checkin.h \
    qrcodefound.h \
    qrnotfound.h

FORMS    += mainwindow.ui \
    eventcreatewindow.ui \
    eventadminwindow.ui \
    usercreatewindow.ui \
    activitycreatewindow.ui \
    listactivities.ui \
    activitysearch.ui \
    activity.ui \
    checkin.ui \
    qrcodefound.ui \
    qrnotfound.ui
