#ifndef QRSCANNER_H
#define QRSCANNER_H

#include <QString>
#include <QImage>

class QRScanner {
	public:
		QRScanner() {}
		QString decode(QImage);
		QString decodeFromFile(QString);
};

#endif
