#ifdef __linux__

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
INCLUDEPATH += /usr/include/opencv

QT += core gui

LIBS += -L/usr/local/lib \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_videoio \
    -lopencv_imgproc \
    -lzbar \
    -lopencv_imgcodecs \

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
