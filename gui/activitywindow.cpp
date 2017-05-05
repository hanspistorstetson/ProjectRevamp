#include "gui/activitywindow.h"
#include "ui_activitywindow.h"
#include "gui/checkinwindow.h"
#include "gui/listactivities.h"
#include "database/user.h"
#include <QString>
ActivityWindow::ActivityWindow(QWidget *parent, Activity* act) :
    QDialog(parent),
    ui(new Ui::ActivityWindow)
{
    ui->setupUi(this);
    activity=act;
    QString name = QString::fromStdString(activity->getActivityName());
    ui->label_2->setText(name);
    std::vector<User*> userList= User::getAllUsers();

    for(unsigned int i; i<userList.size();i++)
    {
        QString username = QString::fromStdString(userList.at(i)->getUserFname());
        ui->listWidget->addItem(username);
    }
}

ActivityWindow::~ActivityWindow()
{
    delete ui;
}

void ActivityWindow::on_QR_released()
{
    CheckInWindow la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}


void ActivityWindow::on_back_released()
{
    ListActivities la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}
