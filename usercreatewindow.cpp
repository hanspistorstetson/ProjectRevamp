#include "usercreatewindow.h"
#include "ui_usercreatewindow.h"

UserCreateWindow::UserCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserCreateWindow)
{
    ui->setupUi(this);
}

UserCreateWindow::~UserCreateWindow()
{
    delete ui;
}

void UserCreateWindow::on_createUserButton_released()
{
    /*
     * This will take in data from fields
     * then close the window
     *
     * */

    this->close();
}



void UserCreateWindow::on_cancelButton_released()
{
    this->close();
}
