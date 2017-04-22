#include "gui/mainwindow.h"
#include "database/database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database::openDatabase();
    MainWindow w;
    w.show();
    int retval = a.exec();
    Database::closeDatabase();
    return retval;
}
