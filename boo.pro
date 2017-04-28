QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

boo {
    TARGET = boo
    TEMPLATE = app
    
SOURCES += main.cpp\
    gui/mainwindow.cpp \
    gui/eventcreatewindow.cpp \
    gui/eventadminwindow.cpp \
    gui/usercreatewindow.cpp \
    gui/activitycreatewindow.cpp \
    gui/listactivities.cpp \
    gui/activitysearch.cpp \
    gui/activitywindow.cpp \
    gui/checkinwindow.cpp \
    gui/qrcodefound.cpp \
    gui/qrnotfound.cpp \
    database/activity.cpp \
    database/checkin.cpp \
    database/database.cpp \
    database/event.cpp \
    database/user.cpp \
    database/sqlite3.c \
    database/dbtest.cpp

HEADERS  += gui/mainwindow.h \
    gui/eventcreatewindow.h \
    gui/eventadminwindow.h \
    gui/usercreatewindow.h \
    gui/activitycreatewindow.h \
    gui/listactivities.h \
    gui/activitysearch.h \
    gui/activitywindow.h \
    gui/checkinwindow.h \
    gui/qrcodefound.h \
    gui/qrnotfound.h \
    database/activity.h \
    database/checkin.h \
    database/database.h \
    database/event.h \
    database/user.h \
    database/sqlite3.h \
    database/dbtest.h

FORMS    += gui/mainwindow.ui \
    gui/eventcreatewindow.ui \
    gui/eventadminwindow.ui \
    gui/usercreatewindow.ui \
    gui/activitycreatewindow.ui \
    gui/listactivities.ui \
    gui/activitysearch.ui \
    gui/activitywindow.ui \
    gui/checkinwindow.ui \
    gui/qrcodefound.ui \
    gui/qrnotfound.ui

DISTFILES += README.txt

}

test {
    TARGET = dbtest
    TEMPLATE = app
    
    SOURCES += test.cpp \
    database/database.cpp \
    database/event.cpp \
    database/user.cpp \
    database/checkin.cpp \
    database/activity.cpp \
    database/sqlite3.c \
    database/dbtest.cpp

    HEADERS += database/database.h \
    database/event.h \
    database/user.h \
    database/checkin.h \
    database/activity.h \
    database/sqlite3.h \
    database/dbtest.h

}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

