#include "gui/qrcodefound.h"
#include "ui_qrcodefound.h"
#include "gui/checkinwindow.h"

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

void QrCodeFound::on_Back_released()
{
    CheckInWindow la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}
