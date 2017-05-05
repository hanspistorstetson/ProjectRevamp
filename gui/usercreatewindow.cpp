#include "gui/usercreatewindow.h"
#include "ui_usercreatewindow.h"
#include "database/user.h"
#include "QRHandler.h"
#include <iostream>

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


    QRHandler handler;



    User* newUser = User::createUser(userName, firstName, lastName, 1);
    std::string UUID = newUser->getUUID();
    std::cout << UUID << std::endl;
    system("mkdir img");
    std::string filepath = "img/" + UUID + ".png";
    handler.generateToFile(QString::fromStdString(UUID), QString::fromStdString(filepath));
    QImage myImage(filepath.c_str());
    std::cout << "here" << std::endl;
    QLabel *label = new QLabel();
    label->setPixmap(QPixmap::fromImage(myImage));
    std::cout << "there" << std::endl;
    label->setWindowModality( Qt::WindowModal );
    label->show();
    delete newUser;
    this->close();
}



void UserCreateWindow::on_cancelButton_released()
{
    this->close();
}
