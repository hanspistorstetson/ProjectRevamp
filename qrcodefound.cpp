#include "qrcodefound.h"
#include "ui_qrcodefound.h"

QrCodeFound::QrCodeFound(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QrCodeFound)
{
    ui->setupUi(this);
}

QrCodeFound::~QrCodeFound()
{
    delete ui;
}
