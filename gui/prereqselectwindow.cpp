#include "prereqselectwindow.h"
#include "ui_prereqselectwindow.h"

PrereqSelectWindow::PrereqSelectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrereqSelectWindow)
{
    ui->setupUi(this);
}

PrereqSelectWindow::~PrereqSelectWindow()
{
    delete ui;
}
