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
    std::string firstName = ui->firstNameTF->text().toStdString();
    std::string lastName = ui->lastNameTF->text().toStdString();
    std::string email = ui->emailTF->text().toStdString();

    this->close();
}



void UserCreateWindow::on_cancelButton_released()
{
    this->close();
}
