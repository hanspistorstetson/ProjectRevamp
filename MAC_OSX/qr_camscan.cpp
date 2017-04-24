#include "qr_camscan.h"
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <zbar.h>
#include <iostream>
using namespace cv;
using namespace std;
using namespace zbar;

QR_CamScan::~QR_CamScan() {
	killSwitch = true;
}

string QR_CamScan::scan() {
	VideoCapture cap(0);
	if (!cap.isOpened()) {
		cout << "Failed to open video source 0!" << endl;
		return "NODATA";
	}
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	cout << "Frame size : " << dWidth << " x " << dHeight << endl;
	namedWindow("BHDT QR Test",CV_WINDOW_AUTOSIZE);
	while (!killSwitch) {
		Mat frame;
		bool read = cap.read(frame);
		if (!read) {
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		Mat grey;
		cvtColor(frame,grey,CV_BGR2GRAY);
		int width = frame.cols;
		int height = frame.rows;
		uchar *raw = (uchar *)grey.data;
		Image image(width, height, "Y800", raw, width * height);
		scanner.scan(image);
		for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
			cout << "Decoded " << symbol->get_type_name() << ". Data: " << symbol->get_data() << endl;
			return symbol->get_data();
		}
		imshow("BHDT QR Test", frame);
		if (waitKey(30) == 27) {
			cout << "Terminating QR Scan..." << endl;
			break;
		}
	}
	return "NODATA";
}
