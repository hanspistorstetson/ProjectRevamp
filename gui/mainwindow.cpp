#include "gui/mainwindow.h"
#include "ui_mainwindow.h"
#include "gui/eventcreatewindow.h"
#include "gui/eventadminwindow.h"


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
    this->hide();
    ecw.setModal(true);
    ecw.exec();
    this->show();
}

void MainWindow::on_eventOpenButton_released()
{

    //admin window will need an event passed to it, probably in constructor
    EventAdminWindow adminWindow;
    this->hide();
    adminWindow.setModal(true);
    adminWindow.exec();
    this->show();
}
