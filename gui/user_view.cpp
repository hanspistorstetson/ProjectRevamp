#include "gui/user_view.h"
#include "ui_user_view.h"
#include "gui/user_search.h"
#include "gui/user_list.h"

user_view::user_view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_view)
{
    ui->setupUi(this);
    ui->listWidget->addItem("User ID, User Name, User email, User Check-Ins");
}

user_view::~user_view()
{
    delete ui;
}

void user_view::on_pushButton_clicked()
{
    user_search userSearch;
    this->hide();
    userSearch.setModal(true);
    userSearch.exec();
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
