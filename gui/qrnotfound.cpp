#include "gui/qrnotfound.h"
#include "ui_qrnotfound.h"

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
