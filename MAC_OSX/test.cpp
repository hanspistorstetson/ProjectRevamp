#include "qr_handler.cpp"
#include "qr_camscan.h"

using namespace std;

int testGenerator() {
	QR_Handler* handle = new QR_Handler();
	handle->generateToFile("HelloWorld");
    cout << handle->readFromFile("./img/HelloWorld.png") << endl;
    delete handle;
	return 1;
}

int testScanner() {
	QR_CamScan* testScan = new QR_CamScan();
	testScan->scan();
	delete testScan;
	return 0;
}

int main(int argc, char* argv[]) {
    return testGenerator();
}
