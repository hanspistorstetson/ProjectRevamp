#ifdef __linux__

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/local/Cellar/opencv3/3.2.0/include

QT += core gui

LIBS += -L/usr/local/Cellar/opencv3/3.2.0/lib \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_videoio \
    -lopencv_imgproc \
    -lopencv_imgcodecs \

LIBS += -L/usr/local/lib -lzbar

SOURCES += \
    ./qr_handler.cpp \
    qr_camscan.cpp \
	test.cpp \
	BitBuffer.cpp \
	QrCode.cpp \
	QrSegment.cpp

INCLUDEPATH += ./include/

HEADERS += \
	include/qr_handler.h \
	include/qr_camscan.h

#endif
