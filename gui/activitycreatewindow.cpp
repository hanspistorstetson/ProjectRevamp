#include "gui/activitycreatewindow.h"
#include "ui_activitycreatewindow.h"
#include "database/activity.h"
#include "gui/prereqselectwindow.h"

ActivityCreateWindow::ActivityCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityCreateWindow)
{
    ui->setupUi(this);
}

ActivityCreateWindow::~ActivityCreateWindow()
{
    delete ui;
}

void ActivityCreateWindow::on_cancelButton_released()
{
    this->close();
}

void ActivityCreateWindow::on_createActivityButton_released()
{
    /* This will take data in textfields
     * and then create activity
     */
    std::string name = ui->actNameTF->text().toStdString();
    std::string status;
   //get activity status
   if(ui->activeRadioButton->isChecked())
   {
       status="active";
   }
   if(ui->upcomingRadioButton->isChecked())
   {
       status="upcoming";
   }

   // populates left list with all existing activities, and adds them to a map

   totalActs = Activity::getAllActivities();
   for(unsigned int i = 0; i<totalActs.size();i++)
   {
       QString name = QString::fromStdString(totalActs.at(i)->getActivityName());
       actMap[i] = totalActs.at(i);
       ui->prereqSelectList->addItem(name);
   }

    if(prereqs.size()>0)
    {
        Activity::createActivity(name,1,status, prereqs);
    } else
    {
        Activity::createActivity(name,1,status);
    }
    this->close();

}

//when an item is double clicked, the activity that exists in the map at that int location is added to the prereq vector
//then the activity name is added to the right-hand list

void ActivityCreateWindow::on_prereqSelectList_itemDoubleClicked(QListWidgetItem *item)
{
    prereqs.push_back(actMap[ui->prereqSelectList->row(item)]);
    ui->prereqAddedList->addItem(item);

}
