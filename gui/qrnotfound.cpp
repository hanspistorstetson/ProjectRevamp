#include "gui/qrnotfound.h"
#include "ui_qrnotfound.h"
#include "gui/checkinwindow.h"

QrnotFound::QrnotFound(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QrnotFound)
{
    ui->setupUi(this);
}

QrnotFound::~QrnotFound()
{
    delete ui;
}

void QrnotFound::on_pushButton_released()
{
    CheckInWindow la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}
