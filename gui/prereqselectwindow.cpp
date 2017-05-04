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
    totalActs = act->getAllActivities();
    for(int i = 0; i<totalActs.size();i++)
    {
        Qstring name = Qstring::fromStdString(totalActs.at(i)->getName());
        actMap[i] = totalActs.at(i);
        ui->prereqSelectList->addItem(name);
    }

}

PrereqSelectWindow::~PrereqSelectWindow()
{
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
//    for(i = 0; i< ui->prereqAddedList->size(); i++)
//    {
//    }
}
