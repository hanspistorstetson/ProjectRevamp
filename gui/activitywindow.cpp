#include "gui/activitywindow.h"
#include "ui_activitywindow.h"

ActivityWindow::ActivityWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityWindow)
{
    ui->setupUi(this);
}

ActivityWindow::~ActivityWindow()
{
    delete ui;
}
