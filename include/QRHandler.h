#ifndef QRHANDLER_H
#define QRHANDLER_H

#include <QString>
#include <QImage>

class QRHandler {
	public:
		QRHandler() {}
		QString scan(QImage);
		QString scanFromFile(QString);
		QPainter* generate(QPainter*, QSize, QString, QColor, QColor);
		bool generateToFile(QString, QString);
};

#endif
