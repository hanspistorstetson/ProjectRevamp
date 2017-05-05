#include "gui/user_search.h"
#include "ui_user_search.h"
#include "gui/user_list.h"
#include "gui/user_view.h"
#include <iostream>

#include <iostream>

user_search::user_search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_search)
{


    ui->setupUi(this);
    std::vector<User*>listOfUsers;
    listOfUsers=User:: getAllUsers();
//    std::cout << listOfUsers.at(14)->getUserLname() << std::endl;
    for (unsigned int t = 0; t<listOfUsers.size();t++)
    {
        QString name = QString::fromStdString(listOfUsers.at(t)->getUserLname());
     //   QString userId = QString::fromStdString(listOfUsers.at(t)->getUUID());
        ui->listWidget->addItem(name);

    }
}

user_search::~user_search()
{
    delete ui;
}

//void user_search::on_pushButton_clicked()
//{
//    user_list userList;
//    this->hide();
//    userList.setModal(true);
//    userList.exec();
//   this->show();
//}

void user_search::on_pushButton_4_clicked()
{
    //Back Button
    user_list userList;
        this->hide();
        userList.setModal(true);
        userList.exec();
       this->show();
}


void user_search::on_listWidget_itemClicked(QListWidgetItem *item)
{
   //item clicked in the widget


    for(unsigned int i=0;i<userSearch.size();i++)
    {
        QString name = QString::fromStdString(userSearch.at(i)->getUserLname());

        if(item->text().toStdString() == userSearch.at(i)->getUserLname())
        {
            user_view* la = new user_view(this, userSearch.at(i));
            this->hide();
            la->setModal(true);
            la->exec();
            delete la;
            this->show();
        }

    }
}

void user_search::on_pushButton_3_clicked()
{
   // Search by Last Name Button
    ui->listWidget->clear();
    userSearch.clear();
    std::string name = ui->nameSearch->text().toStdString();
    userSearch =User::searchByLastName(name);
    for (unsigned int t = 0; t<userSearch.size();t++)
    {
        QString name = QString::fromStdString(userSearch.at(t)->getUserLname());
        ui->listWidget->addItem(name);
    }
}
