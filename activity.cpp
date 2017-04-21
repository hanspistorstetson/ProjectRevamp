#include "activity.h"
#include "ui_activity.h"
#include "checkIn.h"

Activity::Activity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Activity)
{
    ui->setupUi(this);
}

Activity::~Activity()
{
    delete ui;
}

void Activity::on_QR_released()
{
    checkIn la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}
