#include "eventadminwindow.h"
#include "ui_eventadminwindow.h"
#include "usercreatewindow.h"

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

void EventAdminWindow::on_searchUsersButton_released()
{
    UserCreateWindow ucw;
    ucw.setModal(true);
    ucw.exec();
}
