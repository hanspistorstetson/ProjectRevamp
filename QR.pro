TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
include(scan/QZXing.pri)

QT += core gui multimedia widgets

SOURCES += \
	./QRHandler.cpp \
	QRScanner.cpp \
	gen/BitBuffer.cpp \
	gen/QrSegment.cpp \
    test.cpp \
    gen/QrCodeGen.cpp

INCLUDEPATH += ./include/
INCLUDEPATH += ./include/gen/

HEADERS += \
	include/QRHandler.h \
	include/QRScanner.h \
	include/gen/BitBuffer.hpp \
	include/gen/QrSegment.hpp \
    include/gen/QrCodeGen.hpp
