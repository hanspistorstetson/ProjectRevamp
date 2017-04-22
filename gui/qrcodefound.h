#ifndef QRCODEFOUND_H
#define QRCODEFOUND_H

#include <QDialog>

namespace Ui {
class QrCodeFound;
}

class QrCodeFound : public QDialog
{
    Q_OBJECT

public:
    explicit QrCodeFound(QWidget *parent = 0);
    ~QrCodeFound();

private:
    Ui::QrCodeFound *ui;
};

#endif // QRCODEFOUND_H
