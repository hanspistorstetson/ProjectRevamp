#include "listactivities.h"
#include "ui_listactivities.h"
#include "activitysearch.h"
#include "activity.h"

ListActivities::ListActivities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListActivities)
{
    ui->setupUi(this);
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
    Activity la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}

void ListActivities::on_pushButton_2_released()
{
    this->close();
}
