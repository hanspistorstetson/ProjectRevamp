#ifndef EVENTADMINWINDOW_H
#define EVENTADMINWINDOW_H

#include <QDialog>

namespace Ui {
class EventAdminWindow;
}

class EventAdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EventAdminWindow(QWidget *parent = 0);
    ~EventAdminWindow();

private slots:
    void on_activeEventButton_released();

    void on_backButton_released();

private:
    Ui::EventAdminWindow *ui;
};

#endif // EVENTADMINWINDOW_H
