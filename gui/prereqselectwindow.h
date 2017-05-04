
#ifndef PREREQSELECTWINDOW_H
#define PREREQSELECTWINDOW_H
#include "database/activity.h"

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class PrereqSelectWindow;
}

class PrereqSelectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PrereqSelectWindow(QWidget *parent, Activity*);
    ~PrereqSelectWindow();

private slots:
    void on_cancelButton_released();

    void on_prereqSelectList_itemDoubleClicked(QListWidgetItem *item);

    void on_chooseButton_released();

private:
    Ui::PrereqSelectWindow *ui;
    Activity* activity;
    std::map<int, Activity*> actMap;
    std::vector<Activity*> totalActs;
    std::vector<Activity*> prereqs;
};

#endif // PREREQSELECTWINDOW_H

