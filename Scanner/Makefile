CC=g++


INCLUDE_FLAGS=-I/usr/local/include
CFLAGS=-c -Wall $(INCLUDE_FLAGS)
LDFLAGS= -L/usr/local/lib -opencv_core -opencv_highgui -opencv_videoio -opencv_imgproc -lzbar

SOURCES = qr.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=main

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS) Makefile
	$(CC) $(ARCH) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
