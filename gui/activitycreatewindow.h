#ifndef ACTIVITYCREATEWINDOW_H
#define ACTIVITYCREATEWINDOW_H

#include <QDialog>
#include <QListWidgetItem>
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

    void on_prereqSelectList_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::ActivityCreateWindow *ui;
    std::map<int, Activity*> actMap;
    std::vector<Activity*> totalActs;
    std::vector<Activity*> prereqs;

};

#endif // ACTIVITYCREATEWINDOW_H
