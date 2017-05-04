#include "gui/activitysearch.h"
#include "ui_activitysearch.h"
#include "gui/activitywindow.h"
#include "gui/listactivities.h"
#include <QString>
ActivitySearch::ActivitySearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivitySearch)
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

ActivitySearch::~ActivitySearch()
{
    delete ui;
}

void ActivitySearch::on_listWidget_itemClicked(QListWidgetItem *item)
{
<<<<<<< HEAD
    for(unsigned int i=1;i<searchActivity.size();i++)
    {
        QString name = QString::fromStdString(searchActivity.at(i)->getActivityName());
        if(item->text()==name)
=======
    for(int i=1;i<searchActivity.size();i++)
    {
        if(item->text().toUtf8().data()==searchActivity.at(i)->getActivityName());
>>>>>>> cb7a9b11507a7aafbf41d68863b9cbc82717e4d8
        {
            ActivityWindow* la = new ActivityWindow(this, searchActivity.at(i));
            this->hide();
            la->setModal(true);
            la->exec();
            delete la;
            this->show();
        }
    }
}

void ActivitySearch::on_back_released()
{
    ListActivities la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}

void ActivitySearch::on_Search_released()
{
     ui->listWidget->clear();
     searchActivity.clear();
<<<<<<< HEAD
    std::string name = ui->lineEdit->text().toStdString();
     searchActivity=Activity::searchByName(name);
     for (unsigned int t = 0; t<searchActivity.size();t++)
     {
         QString name = QString::fromStdString(searchActivity.at(t)->getActivityName());
         ui->listWidget->addItem(name);
     }
=======
     //searchActivity=Activity::searchByName(lineEdit->text());
     //for (int t = 0; t<listOfActivity.size();t++)
     //{
     //    ui->listWidget->addItem(searchActivity.at(t).getActivityName(););
     //}
>>>>>>> cb7a9b11507a7aafbf41d68863b9cbc82717e4d8

}
