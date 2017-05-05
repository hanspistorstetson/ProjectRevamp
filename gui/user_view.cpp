#include "gui/user_view.h"
#include "ui_user_view.h"
#include "gui/user_search.h"
#include "gui/user_list.h"


user_view::user_view(QWidget *parent , User* user):
    QDialog(parent),
    ui(new Ui::user_view)
{
    ui->setupUi(this);
    std::vector<User*>listOfUsers;
    listOfUsers=User:: getAllUsers();


        QString Fname = QString::fromStdString(user->getUserFname());
        QString Lname = QString::fromStdString(user->getUserLname());
        QString username = QString::fromStdString(user->getUsername());
        QString UUID = QString::fromStdString(user->getUUID());
        ui->listWidget->addItem(UUID + " " + Fname + " " + Lname + " " + username);


}

user_view::~user_view()
{
    delete ui;
}

void user_view::on_pushButton_clicked()
{
    //Back Button
    user_list userList;
        this->hide();
        userList.setModal(true);
        userList.exec();
       this->show();
}

void user_view::on_pushButton_2_clicked()
{
    user_list userList;
    this->hide();
    userList.setModal(true);
    userList.exec();
    this->show();
}
