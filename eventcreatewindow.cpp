#include "eventcreatewindow.h"
#include "ui_eventcreatewindow.h"
#include "eventadminwindow.h"


/*
 *
 *
 *
 *
 *
 * */
eventCreateWindow::eventCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eventCreateWindow)
{
    ui->setupUi(this);
}

eventCreateWindow::~eventCreateWindow()
{
    delete ui;
}

void eventCreateWindow::on_cancelButton_released()
{
    this->close();
}

void eventCreateWindow::on_createButton_released()
{
    //get text from string fields
    //test text for syntax
    //pass data to controller (which will create event in the database)
    //create admin window passing it the event that was just created
    EventAdminWindow eaw;
    this->hide();
    eaw.setModal(true);
    eaw.exec();
    this->show();
}
