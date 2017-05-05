#ifndef ACTIVITYWINDOW_H
#define ACTIVITYWINDOW_H
#include <QDialog>
#include "database/activity.h"

namespace Ui {
class ActivityWindow;
}

class ActivityWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ActivityWindow(QWidget *parent, Activity* activity);
    ~ActivityWindow();
    void updateList();

private slots:
    void on_QR_released();
    void on_back_released();

private:
    Activity* activity;
    Ui::ActivityWindow *ui;
};

#endif // ACTIVITYWINDOW_H
