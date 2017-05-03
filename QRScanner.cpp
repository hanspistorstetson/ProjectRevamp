/**
 * QRScanner.cpp
 * Responsible for the decoding of QR codes.
**/

#include <QZXing.h>
#include <QString>
#include <QImage>

#include "QRScanner.h"

QString QRScanner::decode(QImage img) {
	QZXing decoder;
	decoder.setDecoder( QZXing::DecoderFormat_QR_CODE | QZXing::DecoderFormat_EAN_13 );
	return decoder.decodeImage(img);
}

QString QRScanner::decodeFromFile(QString path) {
	if (path.isEmpty()) return "ERROR";
	return decode(QImage(path));
}
