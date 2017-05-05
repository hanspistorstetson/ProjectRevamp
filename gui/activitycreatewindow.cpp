#include "gui/activitycreatewindow.h"
#include "ui_activitycreatewindow.h"
#include "database/activity.h"
#include "gui/prereqselectwindow.h"
#include <iostream>
using namespace std;

ActivityCreateWindow::ActivityCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityCreateWindow)
{
    ui->setupUi(this);
    ui->prereqSelectList->setDragDropMode(QAbstractItemView::DragDrop);
    ui->prereqAddedList->setDragDropMode(QAbstractItemView::DragDrop);
    totalActs = Activity::getAllActivities();
    for(unsigned int i = 0; i<totalActs.size();i++)
    {
        QString name = QString::fromStdString(totalActs.at(i)->getActivityName());
        actMap[i] = totalActs.at(i);
        ui->prereqSelectList->addItem(name);
    }
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

   if(ui->prereqAddedList->count()>0)
   {
       for(int i = 0; i< ui->prereqAddedList->count();i++)
       {
        for(unsigned int j = 0; j < actMap.size(); j++)
        {
           if(ui->prereqAddedList->item(i)->text().toStdString() == actMap[j]->getActivityName())
            {
                prereqs.push_back(actMap[j]);
            }
        }
       }
       Activity::createActivity(name,1,status, prereqs);
   } else
   {
       Activity::createActivity(name,1,status);
   }
   this->close();

}

//when an item is double clicked, the activity that exists in the map at that int location is added to the prereq vector
//then the activity name is added to the right-hand list

//void ActivityCreateWindow::on_prereqSelectList_itemClicked(QListWidgetItem *item)
//{
//    prereqs.push_back(actMap[ui->prereqSelectList->row(item)]);
//    ui->prereqAddedList->addItem(item);

//}
