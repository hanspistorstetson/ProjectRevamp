#include "gui/listactivities.h"
#include "ui_listactivities.h"

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
