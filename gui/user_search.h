#ifndef USER_SEARCH_H
#define USER_SEARCH_H
#include "database/user.h"
#include <QListWidgetItem>
#include <QDialog>

namespace Ui{
class user_search;
}

class user_search : public QDialog
{
    Q_OBJECT

public:
    explicit user_search(QWidget *parent = 0);
    ~user_search();

private slots:
   // void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    //search by Id Buttob
   // void on_pushButton_2_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

private:
    Ui::user_search *ui;
      std::vector<User*>userSearch;
};

#endif // USER_SEARCH_H
