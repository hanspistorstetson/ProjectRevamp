#include "database/dbtest.h"
#include "database/database.h"
#include "QRHandler.h"
#include "QRScanner.h"

int main(int argc, char** argv) {
    testScanner();
    Database::openDatabase();
    dbtest::testCreating();
    dbtest::testLoading();

    return 0;
}

void testHandler() {
	QRHandler myHandle;
	std::cout << myHandle.generateToFile("Hello World!", "./img/HelloWorld.png");
}

void testScanner() {
	QRScanner myScanner;
	std::cout << myScanner.decodeFromFile("./img/HelloWorld.png").toUtf8().data();
}

