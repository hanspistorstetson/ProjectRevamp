CXX = g++
CXXFLAGS = -Wall -std=c++1y -g
INCLUDES = -I/usr/local/Cellar/opencv3/3.2.0/include
LIBS = -lqrencode -L/usr/local/Cellar/opencv3/3.2.0/lib -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_imgproc -lzbar -lgd


all: clean clearscreen main

qr_handler.o: qr_handler.cpp qr_handler.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c qr_handler.cpp
main: qr_handler.o
	$(CXX) $(CXXFLAGS) $(LIBS)  -o main qr_handler.o

.PHONY: clean clearscreen
clean:
	rm -f *.o qr
clearscreen:
	clear

