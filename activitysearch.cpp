#include "activitysearch.h"
#include "ui_activitysearch.h"
#include "activity.h"
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

void ActivitySearch::on_listWidget_itemClicked(QListWidgetItem *item)
{
    Activity la;
    this->hide();
    la.setModal(true);
    la.exec();
    this->show();
}
