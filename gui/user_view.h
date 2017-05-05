#ifndef USER_VIEW_H
#define USER_VIEW_H

#include <QDialog>

namespace Ui {
class user_view;
}

class user_view : public QDialog
{
    Q_OBJECT

public:
    explicit user_view(QWidget *parent = 0);
    ~user_view();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::user_view *ui;
};

#endif // USER_VIEW_H
