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

private slots:
    void on_Back_released();

private:
    Ui::QrCodeFound *ui;
};

#endif // QRCODEFOUND_H
