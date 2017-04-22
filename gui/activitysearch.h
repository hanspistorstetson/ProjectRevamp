#ifndef ACTIVITYSEARCH_H
#define ACTIVITYSEARCH_H

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

private:
    Ui::ActivitySearch *ui;
};

#endif // ACTIVITYSEARCH_H
