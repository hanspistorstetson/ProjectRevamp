#ifndef EVENTCREATEWINDOW_H
#define EVENTCREATEWINDOW_H

#include <QDialog>

namespace Ui {
class eventCreateWindow;
}

class eventCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit eventCreateWindow(QWidget *parent = 0);
    ~eventCreateWindow();

private slots:
    void on_cancelButton_released();

   // void on_createButton_released();

private:
    Ui::eventCreateWindow *ui;
};

#endif // EVENTCREATEWINDOW_H
