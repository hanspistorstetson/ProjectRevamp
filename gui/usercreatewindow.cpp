#include "gui/usercreatewindow.h"
#include "ui_usercreatewindow.h"
#include "database/user.h"

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
    std::string userName = ui->userNameTF->text().toStdString();

    User::createUser(userName, firstName, lastName, 1);

    this->close();
}



void UserCreateWindow::on_cancelButton_released()
{
    this->close();
}
