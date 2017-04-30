TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core gui multimedia widgets

SOURCES += \
	./QRHandler.cpp \
	QRScanner.cpp \
	gen/BitBuffer.cpp \
	gen/QrCode.cpp \
	gen/QrSegment.cpp \
    test.cpp

INCLUDEPATH += ./include/
INCLUDEPATH += ./include/gen/

HEADERS += \
	include/QRHandler.h \
	include/QRScanner.h \
	include/gen/BitBuffer.hpp \
	include/gen/QrCode.hpp \
	include/gen/QrSegment.hpp
