#include "gui/prereqselectwindow.h"
#include "ui_prereqselectwindow.h"
#include <iostream>

/* TODO
 * add to constructor an integer of number of all activities in an event
 * get that number from the number of elements within the vector of the event's activities
 */

PrereqSelectWindow::PrereqSelectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrereqSelectWindow)
{
    ui->setupUi(this);
    for(int i = 0; i<5;i++)
    {
    ui->prereqListWidget->addItem("Activity information + more information");
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
