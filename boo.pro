CONFIG += c++11
CONFIG -= app_bundle
include(scan/QZXing.pri)
QT       += core gui multimedia widgets multimediawidgets
INCLUDEPATH += ./include/
INCLUDEPATH += ./include/gen/
TEMPLATE = app

SOURCES += main.cpp \
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
    gui/user_list.cpp \
    gui/user_search.cpp \
    gui/user_view.cpp\
    database/activity.cpp \
    database/checkin.cpp \
    database/database.cpp \
    database/event.cpp \
    database/user.cpp \
    database/sqlite3.c \
    gui/prereqselectwindow.cpp \
    database/guid.cpp \
    database/dbtest.cpp \
    ./QRHandler.cpp \
    QRScanner.cpp \
    gen/BitBuffer.cpp \
    gen/QrCodeGen.cpp \
    gen/QrSegment.cpp \
    QRCapture.cpp \
    imagesettings.cpp \
    videosettings.cpp



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
    gui/user_list.h \
    gui/user_search.h \
    gui/user_view.h \
    database/activity.h \
    database/guid.h   \
    database/checkin.h \
    database/database.h \
    database/event.h \
    database/user.h \
    database/sqlite3.h \
    database/dbtest.h \
    gui/prereqselectwindow.h \
    include/QRHandler.h \
    include/QRScanner.h \
    include/gen/BitBuffer.hpp \
    include/gen/QrCodeGen.hpp \
    include/gen/QrSegment.hpp \
    include/imagesettings.h \
    include/videosettings.h \
    include/QRCapture.h

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
    gui/qrnotfound.ui \
    gui/user_list.ui \
    gui/user_search.ui \
    gui/user_view.ui \ 
    gui/prereqselectwindow.ui \
    imagesettings.ui \
    videosettings.ui \
    camera.ui

DISTFILES += README.txt

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
win32 {
    DEFINES += GUID_WINDOWS
    LIBS += -lole32
}
unix:!macx {
    DEFINES += GUID_LIBUUID
    LIBS += -luuid
}
macx: {
    DEFINES += GUID_CFUUID
    LIBS += -framework CoreFoundation
}


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

