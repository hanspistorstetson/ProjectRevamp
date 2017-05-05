#include "gui/user_list.h"
#include "ui_user_list.h"
#include "gui/mainwindow.h"
#include "gui/user_search.h"
#include "gui/user_view.h"
#include "gui/eventadminwindow.h"
#include "database/user.h"
#include <vector>

#include <iostream>
user_list::user_list(QWidget *parent) :
    QDialog(parent),
    //ui(new Ui::user_list)
    ui(new Ui::user_list)
{



    ui->setupUi(this);
    std::vector<User*>listOfUsers;
    listOfUsers=User::getAllUsers();
    for (unsigned int t = 0; t<listOfUsers.size();t++)
    {
      //  QString userId = QString::fromStdString(listOfUsers.at(t)->getUUID());
        QString username = QString::fromStdString(listOfUsers.at(t)->getUsername());
        ui->listWidget->addItem(username);
    }
}

user_list::~user_list()
{
    delete ui;
}

void user_list::on_pushButton_clicked()
{
   this->close();
}

//void user_list::on_pushButton_2_clicked()
//{

//}

void user_list::on_pushButton_3_clicked()
{
    user_search userSearch;
    this->hide();
    userSearch.setModal(true);
    userSearch.exec();
    this->show();
}

void user_list::on_listWidget_itemClicked(QListWidgetItem *item)
{

    std::vector<User*> user = User::getAllUsers();
//    std::string val = user->getUsername();
//    std::string val2 =  item->text().toStdString();
//    std::cout << val << "<- val,";
//    std::cout << val2;

//  /*  User(size_t, std::string, std::string, std::string, std::string, size_t);
//    size_t userid;
//    std::string uuid;
//    size_t eventid;
//    std::string username;
//    std::string fname;....
//    std::string lna*/me;....


    for(unsigned int i = 0; i< user.size(); i++)
    {
        if(user.at(i)->getUsername() == item->text().toStdString())
        {
            user_view* userView = new user_view(this,user.at(i));
            this->hide();
            userView->setModal(true);
            userView->exec();
            delete userView;
            this->show();
        }
    }
}
