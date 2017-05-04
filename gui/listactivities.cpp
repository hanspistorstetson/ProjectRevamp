#include "gui/listactivities.h"
#include "ui_listactivities.h"
#include "gui/activitysearch.h"
#include "gui/activitywindow.h"
#include "database/activity.h"
#include <vector>
ListActivities::ListActivities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListActivities)
{
    ui->setupUi(this);
    std::vector<Activity*>listOfActivity;
    listOfActivity=Activity::getAllActivities();
    for (unsigned int t = 0; t<listOfActivity.size();t++)
    {
<<<<<<< HEAD
        QString name = QString::fromStdString(listOfActivity.at(t)->getActivityName());
        ui->listWidget->addItem(name);
=======
        //ui->listWidget->addItem(listOfActivity.at(t)->getActivityName());
>>>>>>> cb7a9b11507a7aafbf41d68863b9cbc82717e4d8
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
            ActivityWindow* la = new ActivityWindow(this, acts.at(i));
            this->hide();
            la->setModal(true);
            la->exec();
            delete la;
            this->show();
        }
    }
}

void ListActivities::on_pushButton_2_released()
{
    this->close();
}
