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

    //Camera camera;
    //camera.show();


    int retval = a.exec();
    Database::closeDatabase();

<<<<<<< HEAD
    return 0;
=======
    return retval;
>>>>>>> cb5c307bb75efedd56ff68cc1bab54b13e4eda98
}


