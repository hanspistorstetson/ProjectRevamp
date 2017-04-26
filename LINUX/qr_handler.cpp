/**
 *	qr_handler.cpp
 *	Responsible for generation of QR Codes. Relies on a library written by
 *	Nayuki (github.com/nayuki) to do so. Original versions of this code relied on
 *	qrencode, however, it does not port well to Windows.
**/
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include <zbar.h>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "qr_handler.h"
#include "QrCode.hpp"
#include <QPainter>
#include <QString>

using namespace std;
using namespace zbar;
using namespace cv;
using namespace qrcodegen;

bool QR_Handler::generateToFile(QString data) {
	QString path = "./img/" + data + ".png";
	if (path.isEmpty()) return false;
	QImage img(400, 400, QImage::Format_ARGB32);
	QPainter* painter = new QPainter();
	painter->begin(&img);
	qrcode_png(painter, QSize(400,400), data, QColor("black"), QColor("white"));
	painter->end();
	img.save(path);
	delete painter;
	return true;
}

QPainter* QR_Handler::qrcode_png(QPainter *painter, QSize sz, QString data, QColor fg, QColor bg)
{
	char *str=data.toUtf8().data();
	QrCode qr = QrCode::encodeText(str, QrCode::Ecc::HIGH);
	const int s=qr.size>0?qr.size:1;
	const double w=sz.width();
	const double h=sz.height();
	const double aspect=w/h;
	const double size=((aspect>1.0)?h:w);
	const double scale=size/(s+2);
	painter->setPen(Qt::NoPen);
	painter->setBrush(bg);
	for(int y=0; y<400; y++) {
		for(int x=0; x<400; x++) {
			QRectF r(x, y, 1, 1);
			painter->drawRects(&r,1);
		}
	}
	painter->setBrush(fg);
	for(int y=0; y<s; y++) {
		for(int x=0; x<s; x++) {
			const int color=qr.getModule(x, y);  // 0 for white, 1 for black
			if(0!=color) {
				const double rx1=(x+1)*scale, ry1=(y+1)*scale;
				QRectF r(rx1, ry1, scale, scale);
				painter->drawRects(&r,1);
			}
		}
	}
	return painter;
}

string QR_Handler::read(Mat img) {
	zbar::ImageScanner scanner;
	if (!img.data) {
		cout << "COULDN'T FIND FILE" << endl;
		return NULL;
	}
	Mat grey;
	cvtColor(img, grey, CV_BGR2GRAY);
	uchar* raw = (uchar*) grey.data;
	zbar::Image image(img.cols, img.rows, "Y800", raw, img.cols * img.rows);
	scanner.scan(image);
	for (zbar::Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
		return symbol->get_data();
	}
	return NULL;
}

string QR_Handler::readFromFile(string dir) {
	Mat image = imread(dir, CV_LOAD_IMAGE_COLOR);
	if (!image.data) return "ERROR";
	else {
		string retVal = read(image);
		return retVal;
	}
}
