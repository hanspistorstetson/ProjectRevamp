/**
 * QRHandler.cpp
 * Responsible for the generation of QR Images.
**/

#include <QString>
#include <QImage>
#include <QPainter>
#include <QSize>

#include "QRHandler.h"
#include "QrCodeGen.hpp"

using namespace std;
using namespace qrcodegen;

QPainter* QRHandler::generate(QPainter* painter, QSize sz, QString data, QColor fg, QColor bg) {
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
			const int color=qr.getModule(x, y);
			if(0 != color) {
				const double rx1=(x+1)*scale, ry1=(y+1)*scale;
				QRectF r(rx1, ry1, scale, scale);
				painter->drawRects(&r,1);
			}
		}
	}
	return painter; // IT IS THE RESPONSIBILITY OF WHATEVER RECIEVES THIS TO DELETE IT!
}

bool QRHandler::generateToFile(QString data, QString path) {
	if (path.isEmpty()) return false;
	QImage img(400, 400, QImage::Format_ARGB32);
	QPainter* painter = new QPainter();
	painter->begin(&img);
	generate(painter, QSize(400,400), data, QColor("black"), QColor("white"));
	painter->end();
	img.save(path);
	delete painter;
	return true;
}
