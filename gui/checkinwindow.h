#ifndef CHECKINWINDOW_H
#define CHECKINWINDOW_H
#include <QDialog>

namespace Ui {
class CheckInWindow;
}

class CheckInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CheckInWindow(QWidget *parent = 0);
    ~CheckInWindow();

private slots:
    void on_Back_released();

    void on_Scan_released();

private:
    Ui::CheckInWindow *ui;
};
#endif // CHECKINWINDOW_H
