#include "gui/activitysearch.h"
#include "ui_activitysearch.h"
#include "gui/activitywindow.h"
#include "gui/listactivities.h"
ActivitySearch::ActivitySearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivitySearch)
{
    ui->setupUi(this);
    std::vector<Activity*>listOfActivity;
    listOfActivity=Activity::getAllActivities();
    for (int t = 0; t<listOfActivity.size();t++)
    {
        //ui->listWidget->addItem(listOfActivity.at(t)->getActivityName());
    }
}

ActivitySearch::~ActivitySearch()
{
    delete ui;
}

void ActivitySearch::on_listWidget_itemClicked(QListWidgetItem *item)
{
    for(int i=1;i<searchActivity.size();i++)
    {
        if(item->text().toUtf8().data()==searchActivity.at(i)->getActivityName());
        {
            ActivityWindow la;
            this->hide();
            la.setModal(true);
            la.exec();
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
     //searchActivity=Activity::searchByName(lineEdit->text());
     //for (int t = 0; t<listOfActivity.size();t++)
     //{
     //    ui->listWidget->addItem(searchActivity.at(t).getActivityName(););
     //}

}
