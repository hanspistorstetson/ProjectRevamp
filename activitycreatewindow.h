#ifndef ACTIVITYCREATEWINDOW_H
#define ACTIVITYCREATEWINDOW_H

#include <QDialog>

namespace Ui {
class ActivityCreateWindow;
}

class ActivityCreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ActivityCreateWindow(QWidget *parent = 0);
    ~ActivityCreateWindow();

private:
    Ui::ActivityCreateWindow *ui;
};

#endif // ACTIVITYCREATEWINDOW_H
