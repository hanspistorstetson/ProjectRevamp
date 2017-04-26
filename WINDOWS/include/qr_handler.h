#ifndef QR_HANDLER_H
#define QR_HANDLER_H

#include <opencv2/core/core.hpp>
#include <string>
#include <gd.h>

using namespace std;
using namespace cv;

class QR_Handler {
	public:
		QR_Handler() {}
		gdImagePtr generate(string);
		string read(Mat);
		string readFromFile(string);
		bool generateToFile(string);
	private:
		gdImagePtr qrcode_png(QRcode*, int[], int[], int, int);
};

#endif
