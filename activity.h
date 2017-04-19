#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QDialog>

namespace Ui {
class Activity;
}

class Activity : public QDialog
{
    Q_OBJECT

public:
    explicit Activity(QWidget *parent = 0);
    ~Activity();

private:
    Ui::Activity *ui;
};

#endif // ACTIVITY_H
