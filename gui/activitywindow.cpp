#include "gui/activitywindow.h"
#include "ui_activitywindow.h"
#include "gui/checkinwindow.h"
#include "gui/listactivities.h"
#include <QString>
#include "database/checkin.h"
#include "QRCapture.h"
#include "database/user.h"
#include "QMessageBox"
#include <vector>
#include <iostream>

ActivityWindow::ActivityWindow(QWidget *parent, Activity* act) :
    QDialog(parent),
    ui(new Ui::ActivityWindow)
{
    ui->setupUi(this);
    activity=act;
    QString name = QString::fromStdString(activity->getActivityName());
    QString stat = QString::fromStdString(activity->getStatus());

    ui->label_2->setText(name);
    ui->status_label->setText(stat);


    updateList();

}

ActivityWindow::~ActivityWindow()
{
    delete ui;
}

void ActivityWindow::on_QR_released()
{
    if(activity->getStatus() == "inactive") {
        QMessageBox::warning(this, tr("Error"), QString("This Activity is Inactive"));
    }else {
    Camera* scanner = new Camera(this, activity, this);
    scanner->show();
    }
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
   std::cout<<activity->getPrereqs().size()<<std::endl;
   for(unsigned int i = 0; i<activity->getPrereqs().size();i++)
   {
      QString name = QString::fromStdString(activity->getPrereqs().at(i)->getActivityName());
       ui->prereq_list->addItem(name);
       ui->prereq_list->update();
   }



}

void ActivityWindow::on_back_released()
{
    this->close();
}

void ActivityWindow::on_pushButton_released()
{
    if(activity->getStatus() == "active") {
        activity->setStatus("inactive");
    }else {
        activity->setStatus("active");
    }
    QString stat = QString::fromStdString(activity->getStatus());
    ui->status_label->setText(stat);
}
