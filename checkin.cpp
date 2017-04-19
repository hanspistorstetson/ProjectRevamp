#include "checkin.h"
#include "ui_checkin.h"

checkIn::checkIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkIn)
{
    ui->setupUi(this);
}

checkIn::~checkIn()
{
    delete ui;
}
