CC=g++


INCLUDE_FLAGS=-I/usr/local/Cellar/opencv3/3.2.0/include
CFLAGS=-c -Wall $(INCLUDE_FLAGS)
LDFLAGS= -L/usr/local/Cellar/opencv3/3.2.0/lib -lopencv_core -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_imgproc -lzbar


SOURCES = qr.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=main

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS) Makefile
	$(CC) $(ARCH) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
