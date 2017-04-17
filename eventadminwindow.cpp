#include "eventadminwindow.h"
#include "ui_eventadminwindow.h"

EventAdminWindow::EventAdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventAdminWindow)
{
    ui->setupUi(this);
}

EventAdminWindow::~EventAdminWindow()
{
    delete ui;
}

void EventAdminWindow::on_backButton_released()
{
    this->close();
}
