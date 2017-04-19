#include "eventadminwindow.h"
#include "ui_eventadminwindow.h"
#include "usercreatewindow.h"
#include "activitycreatewindow.h"
#include "listactivities.h"

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

void EventAdminWindow::on_addUsersButton_released()
{
    UserCreateWindow ucw;
    ucw.setModal(true);
    ucw.exec();
}

void EventAdminWindow::on_addActsButton_released()
{
    ActivityCreateWindow acw;
    acw.setModal(true);
    acw.exec();
}

void EventAdminWindow::on_activeEventButton_released()
{
    /*  This will set event to 'active'
     *
     */
}

void EventAdminWindow::on_deactEventButton_released()
{
    /*  This will deactivate event, or set event to 'inactive'
     *
     */
}

void EventAdminWindow::on_listActsButton_released()
{
    ListActivities la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}
