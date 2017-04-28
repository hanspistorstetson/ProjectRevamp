#ifndef USER_SEARCH_H
#define USER_SEARCH_H

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
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::user_search *ui;
};

#endif // USER_SEARCH_H
