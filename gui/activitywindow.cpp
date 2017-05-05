#include "gui/activitywindow.h"
#include "ui_activitywindow.h"
#include "gui/checkinwindow.h"
#include "gui/listactivities.h"
#include <QString>
#include "database/checkin.h"
#include "QRCapture.h"
#include "database/user.h"
#include <vector>
#include <iostream>

ActivityWindow::ActivityWindow(QWidget *parent, Activity* act) :
    QDialog(parent),
    ui(new Ui::ActivityWindow)
{
    ui->setupUi(this);
    activity=act;
    QString name = QString::fromStdString(activity->getActivityName());
    ui->label_2->setText(name);

    updateList();

}

ActivityWindow::~ActivityWindow()
{
    delete ui;
}

void ActivityWindow::on_QR_released()
{
    Camera* scanner = new Camera(this, activity, this);
    scanner->show();
}

void ActivityWindow::updateList()
{
    ui->listWidget->clear();
   std::vector<User*> users = Checkin::getUsersbyActivityId(activity->getId());
   for(unsigned int i = 0; i<users.size();i++)
   {
      QString name = QString::fromStdString(users[i]->getUserFname());
       ui->listWidget->addItem(name);
       ui->listWidget->update();
   }
}

void ActivityWindow::on_back_released()
{
    this->close();
}
