#include "gui/listactivities.h"
#include "ui_listactivities.h"
#include "gui/activitysearch.h"
#include "gui/activitywindow.h"
#include "database/activity.h"
#include <vector>
#include <iostream>

ListActivities::ListActivities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListActivities)
{
    ui->setupUi(this);
    std::vector<Activity*>listOfActivity;
    listOfActivity=Activity::getAllActivities();
    for (unsigned int t = 0; t<listOfActivity.size();t++)
    {
        QString name = QString::fromStdString(listOfActivity.at(t)->getActivityName());
        ui->listWidget->addItem(name);
    }
}

ListActivities::~ListActivities()
{
    delete ui;
}

void ListActivities::on_pushButton_released()
{
    ActivitySearch la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}

void ListActivities::on_listWidget_itemClicked(QListWidgetItem *item)
{
    std::vector<Activity*> acts = Activity::getAllActivities();
    for(unsigned int i = 0; i< acts.size(); i++)
    {
        if(acts.at(i)->getActivityName() == item->text().toStdString())
        {
            std::cout << acts.at(i)->getCheckins().size() << std::endl;
            ActivityWindow* la = new ActivityWindow(this, acts.at(i));
            this->hide();
            la->setModal(true);
            la->exec();
            this->show();
        }
    }
}

void ListActivities::on_pushButton_2_released()
{
    this->close();
}
