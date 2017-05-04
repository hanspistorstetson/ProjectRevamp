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
        QString name = QString::fromStdString(listOfActivity.at(t)->getActivityName());
        ui->listWidget->addItem(name);

    }
}

ActivitySearch::~ActivitySearch()
{
    delete ui;
}

void ActivitySearch::on_listWidget_itemClicked(QListWidgetItem *item)
{

    for(unsigned int i=1;i<searchActivity.size();i++)
    {
        QString name = QString::fromStdString(searchActivity.at(i)->getActivityName());
        if(item->text()==name)   
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
     std::string name = ui->lineEdit->text().toStdString();
     searchActivity=Activity::searchByName(name);
     for (unsigned int t = 0; t<searchActivity.size();t++)
     {
         QString name = QString::fromStdString(searchActivity.at(t)->getActivityName());
         ui->listWidget->addItem(name);
     }

}
