#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "eventcreatewindow.h"
#include "eventadminwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeVisible()
{
    this->show();

}

void MainWindow::makeHidden()
{
    this->hide();

}

void MainWindow::on_eventCreateButton_released()
{
    eventCreateWindow ecw;
    ecw.setModal(true);
    ecw.exec();
    this->hide();
}

void MainWindow::on_eventOpenButton_released()
{

    //admin window will need an event passed to it, probably in constructor
    EventAdminWindow adminWindow;
    this->hide();
    adminWindow.setModal(true);
    adminWindow.exec();
}
