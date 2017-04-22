#include "gui/checkinwindow.h"
#include "ui_checkinwindow.h"

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
