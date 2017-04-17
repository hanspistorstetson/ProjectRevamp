#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void makeVisible();
    void makeHidden();
    ~MainWindow();

private slots:
    void on_pushButton_released();

    void on_eventCreateButton_released();

    void on_eventOpenButton_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
