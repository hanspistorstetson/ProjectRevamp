// testing file for QRHandler & QRScanner

#include <iostream>

#include "QRHandler.h"

void testHandler() {
	QRHandler myHandle;
	std::cout << myHandle.generateToFile("Hello World!", "./img/HelloWorld.png");
}

int main(int argc, char** argv) {
	testHandler();
	return 0;
}
