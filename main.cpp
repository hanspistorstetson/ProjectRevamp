#include "mainwindow.h"
#include <QApplication>
#include <cstdlib>
#include <iostream>
#include "database/sqlite3.h"
#include <cstring>
#include "database/dbtest.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Testing database
    dbtest::test();

    return a.exec();
}
