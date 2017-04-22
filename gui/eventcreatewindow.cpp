#include "gui/eventcreatewindow.h"
#include "ui_eventcreatewindow.h"
#include "gui/eventadminwindow.h"
#include <iostream>

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
    //get text from string fields -- done
    //test text for syntax -- TODO
    //pass data to controller (which will create event in the database) -- TODO
    //create admin window passing it the event that was just created -- TODO
    std::string name = ui->nameTF->text().toStdString();
    std::string desc = ui->descrTextEdit->toPlainText().toStdString();
    std::string org = ui->orgTF->text().toStdString();
    //get event status from radio buttons -- TODO

    EventAdminWindow eaw;


    this->hide();
    eaw.setModal(true);
    eaw.exec();
    this->show();
}
