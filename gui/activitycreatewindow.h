#ifndef ACTIVITYCREATEWINDOW_H
#define ACTIVITYCREATEWINDOW_H

#include <QDialog>
#include "database/activity.h"

namespace Ui {
class ActivityCreateWindow;
}

class ActivityCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ActivityCreateWindow(QWidget *parent = 0);
    ~ActivityCreateWindow();

private slots:
    void on_cancelButton_released();

    void on_createActivityButton_released();

    void on_preReqSelectButton_released();

private:
    Ui::ActivityCreateWindow *ui;
    Activity* act;

};

#endif // ACTIVITYCREATEWINDOW_H
