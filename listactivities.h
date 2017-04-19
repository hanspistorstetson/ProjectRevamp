#ifndef LISTACTIVITIES_H
#define LISTACTIVITIES_H

#include <QDialog>

namespace Ui {
class ListActivities;
}

class ListActivities : public QDialog
{
    Q_OBJECT

public:
    explicit ListActivities(QWidget *parent = 0);
    ~ListActivities();

private:
    Ui::ListActivities *ui;
};

#endif // LISTACTIVITIES_H
