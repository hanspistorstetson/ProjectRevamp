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
    explicit ActivityWindow(QWidget *parent, Activity*);
    ~ActivityWindow();

private slots:
    void on_QR_released();


    void on_back_released();

private:
    Ui::ActivityWindow *ui;
    Activity* activity;
};

#endif // ACTIVITYWINDOW_H
