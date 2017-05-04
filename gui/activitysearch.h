#ifndef ACTIVITYSEARCH_H
#define ACTIVITYSEARCH_H
#include "database/activity.h"
#include <QListWidgetItem>
#include <QDialog>

namespace Ui {
class ActivitySearch;
}

class ActivitySearch : public QDialog
{
    Q_OBJECT

public:
    explicit ActivitySearch(QWidget *parent = 0);
    ~ActivitySearch();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_back_released();

    void on_Search_released();

private:
    Ui::ActivitySearch *ui;
    std::vector<Activity*>searchActivity;
};

#endif // ACTIVITYSEARCH_H
