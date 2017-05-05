#ifndef LISTACTIVITIES_H
#define LISTACTIVITIES_H

#include <QListWidgetItem>
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
    int i=1;

private slots:
    void on_pushButton_released();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_2_released();

private:
    Ui::ListActivities *ui;
};

#endif // LISTACTIVITIES_H
