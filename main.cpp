#include "QRCapture.h"
#include "gui/mainwindow.h"
#include "database/database.h"
#include <QApplication>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "database/dbtest.h"
#include <QtWidgets>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database::openDatabase();
    MainWindow w;
    w.show();


    //Testing database
    //dbtest::testCreating();
    //dbtest::testLoading();

    int retval = a.exec();
    Database::closeDatabase();
    return 0;
}


