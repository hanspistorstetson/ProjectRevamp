TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += /usr/include/opencv
LIBS += -L/usr/local/lib \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_videoio \
    -lopencv_imgproc \
    -lzbar \
    -lopencv_imgcodecs \
    -lqrencode \
    -lgd

SOURCES += \
    ./qr_handler.cpp \
    qr_camscan.cpp \
    test.cpp

INCLUDEPATH += ./include/

HEADERS += \
	include/qr_handler.h \
	include/qr_camscan.h


