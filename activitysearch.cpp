#include "activitysearch.h"
#include "ui_activitysearch.h"

ActivitySearch::ActivitySearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivitySearch)
{
    ui->setupUi(this);
}

ActivitySearch::~ActivitySearch()
{
    delete ui;
}
