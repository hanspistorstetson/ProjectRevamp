#ifndef PREREQSELECTWINDOW_H
#define PREREQSELECTWINDOW_H

#include <QDialog>

namespace Ui {
class PrereqSelectWindow;
}

class PrereqSelectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PrereqSelectWindow(QWidget *parent = 0);
    ~PrereqSelectWindow();

private slots:
    void on_cancelButton_released();

private:
    Ui::PrereqSelectWindow *ui;
};

#endif // PREREQSELECTWINDOW_H
