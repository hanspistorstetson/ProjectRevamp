#ifndef QR_HANDLER_H
#define QR_HANDLER_H

#include <opencv2/core/core.hpp>
#include <string>
#include <QPainter>
#include <QString>

using namespace std;
using namespace cv;

class QR_Handler {
	public:
		QR_Handler() {}
		string read(Mat);
		string readFromFile(string);
		bool generateToFile(QString);
	private:
		QPainter* qrcode_png(QPainter*, QSize, QString, QColor, QColor);
};

#endif
