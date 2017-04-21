#ifndef ACTIVITYSEARCH_H
#define ACTIVITYSEARCH_H

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

private:
    Ui::ActivitySearch *ui;
};

#endif // ACTIVITYSEARCH_H
