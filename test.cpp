#include "qr_handler.cpp"
#include "qr_camscan.h"

using namespace std;

int testGeneratorOld() {
	boost::uuids::uuid uuid = boost::uuids::random_generator()();
	const std::string tmp = boost::lexical_cast<std::string>(uuid);
	cout << tmp << endl;
	QR_Handler handle = QR_Handler();
	gdImagePtr ptr = handle.generate(tmp);
	string path = "temp.png";
	FILE* out = fopen(path.c_str(), "w+");
	if (out == NULL) {
		cout << "Error opening " << path << endl;
		return 1;
	}
	gdImagePng(ptr, out);
	gdImageDestroy(ptr);
	fclose(out);
	cv::Mat image = cv::imread(path, CV_LOAD_IMAGE_COLOR);
	if (!image.data) {
		cout << "Couldn't find file" << endl;
		return -1;
	} else {
		cout << handle.read(image) << endl;
		remove(path.c_str());
		return 0;
	}
}

int testGenerator() {
	QR_Handler* handle = new QR_Handler();
	handle->generateToFile("HelloWorld");
	cout << handle->readFromFile("./img/HelloWorld.gif") << endl;
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
	return testScanner();
}
