#include "activity.h"
#include "ui_activity.h"

Activity::Activity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Activity)
{
    ui->setupUi(this);
}

Activity::~Activity()
{
    delete ui;
}
