#ifndef USERCREATEWINDOW_H
#define USERCREATEWINDOW_H

#include <QDialog>

namespace Ui {
class UserCreateWindow;
}

class UserCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserCreateWindow(QWidget *parent = 0);
    ~UserCreateWindow();

private slots:
    void on_createUserButton_released();

    void on_cancelButton_released();

private:
    Ui::UserCreateWindow *ui;
};

#endif // USERCREATEWINDOW_H
