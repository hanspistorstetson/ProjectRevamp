#include "gui/user_search.h"
#include "ui_user_search.h"
#include "gui/user_list.h"
#include "gui/user_view.h"

user_search::user_search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_search)
{
    ui->setupUi(this);
    ui->listWidget->addItem("User ID , User Name");
}

user_search::~user_search()
{
    delete ui;
}

void user_search::on_pushButton_clicked()
{
    user_list userList;
    this->hide();
    userList.setModal(true);
    userList.exec();
    this->show();
}

void user_search::on_pushButton_4_clicked()
{
    user_view userView;
    this->hide();
    userView.setModal(true);
    userView.exec();
    this->show();
}
