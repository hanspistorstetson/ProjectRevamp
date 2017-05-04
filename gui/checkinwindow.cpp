#include "gui/checkinwindow.h"
#include "ui_checkinwindow.h"
#include "gui/activitywindow.h"
#include "gui/qrcodefound.h"

CheckInWindow::CheckInWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckInWindow)
{
    ui->setupUi(this);
}

CheckInWindow::~CheckInWindow()
{
    delete ui;
}

void CheckInWindow::on_Back_released()
{
  /*  ActivityWindow la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
    */
}

void CheckInWindow::on_Scan_released()
{
    QrCodeFound la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}
