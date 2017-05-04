TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
include(scan/QZXing.pri)

QT += core gui multimedia widgets multimediawidgets

INCLUDEPATH += ./include/
INCLUDEPATH += ./include/gen/

HEADERS += \
    imagesettings.h \
    videosettings.h \
    include/QRHandler.h \
	include/QRScanner.h \
	include/gen/BitBuffer.hpp \
	include/gen/QrSegment.hpp \
    include/gen/QrCodeGen.hpp \
    QRCapture.h

SOURCES += \
    main.cpp \
    imagesettings.cpp \
    videosettings.cpp \
    QRHandler.cpp \
	QRScanner.cpp \
	gen/BitBuffer.cpp \
	gen/QrSegment.cpp \
    gen/QrCodeGen.cpp \
    QRCapture.cpp

FORMS += \
    camera.ui \
    videosettings.ui \
    imagesettings.ui
