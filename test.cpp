#include "database/dbtest.h"
#include "database/database.h"

int main() {
    
    Database::openDatabase();
    dbtest::testCreating();
    dbtest::testLoading();

    return 0;

// testing file for QRHandler & QRScanner
/*
#include <iostream>

#include "QRHandler.h"
#include "QRScanner.h"

void testHandler() {
	QRHandler myHandle;
	std::cout << myHandle.generateToFile("Hello World!", "./img/HelloWorld.png");
}

void testScanner() {
	QRScanner myScanner;
	std::cout << myScanner.decodeFromFile("./img/HelloWorld.png").toUtf8().data();
}

int main(int argc, char** argv) {
	testScanner();
	return 0;
*/
}
