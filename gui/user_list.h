#ifndef USER_LIST_H
#define USER_LIST_H

#include <QListWidgetItem>
#include <QDialog>

namespace Ui {
class user_list;
}

class user_list : public QDialog
{
    Q_OBJECT

public:
    explicit user_list(QWidget *parent = 0);
    ~user_list();
    int i =1;  // included

private slots:
    void on_pushButton_clicked();

   // void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::user_list *ui;
};

#endif // USER_LIST_H
