#include "gui/prereqselectwindow.h"
#include "ui_prereqselectwindow.h"
#include "database/activity.h"

/* TODO
 *
 *
 */

PrereqSelectWindow::PrereqSelectWindow(QWidget *parent, Activity* act) :
    QDialog(parent),
    ui(new Ui::PrereqSelectWindow)
{
    ui->setupUi(this);
    activity = act;
    totalActs = act->getAllActivities();
    for(unsigned int i = 0; i<totalActs.size();i++)
    {
        QString name = QString::fromStdString(totalActs.at(i)->getActivityName());
        actMap[i] = totalActs.at(i);
        ui->prereqSelectList->addItem(name);
    }

}

PrereqSelectWindow::~PrereqSelectWindow()
{
    delete activity;
    delete ui;
}


void PrereqSelectWindow::on_cancelButton_released()
{
    this->close();
}

void PrereqSelectWindow::on_prereqSelectList_itemDoubleClicked(QListWidgetItem *item)
{

    prereqs.push_back(actMap[ui->prereqSelectList->row(item)]);
    ui->prereqAddedList->addItem(item);

}


void PrereqSelectWindow::on_chooseButton_released()
{
    activity->addPrereqs(prereqs);
}
