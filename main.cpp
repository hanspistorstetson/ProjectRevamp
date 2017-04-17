<<<<<<< HEAD
#include "mainwindow.h"
#include <QApplication>
=======
>>>>>>> parent of 7e1fd01... cleaning master
#include <cstdlib>
#include <iostream>
#include "sqlite3.h"
#include <cstring>
<<<<<<< HEAD

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    //stuff from database main file
    sqlite3 *db;
    int retval;
    retval = sqlite3_open("test.db", &db);
    if (retval != 0) {
        std::cout << "Cannot open test.db: " << sqlite3_errcode(db) << std::endl;
        exit(1);
    }

    std::cout << "Succsesfully opened." << std::endl;

    std::cout << "Creating a table..." << std::endl;
=======
using namespace std;

int main() {
    
    sqlite3 *db;

    int retval;

    retval = sqlite3_open("test.db", &db);
    if (retval != 0) {
        cout << "Cannot open test.db: " << sqlite3_errcode(db) << endl;
        exit(1);
    }
    cout << "Succsesfully opened." << endl;

    cout << "Creating a table..." << endl;
>>>>>>> parent of 7e1fd01... cleaning master

    char* errmsg;
    retval = sqlite3_exec(db, "CREATE TABLE mytable (id int, val text, x double);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
<<<<<<< HEAD
        std::cout << "Error in previous command: " << errmsg << std::endl;
=======
        cout << "Error in previous command: " << errmsg << endl;
>>>>>>> parent of 7e1fd01... cleaning master
        sqlite3_free(errmsg);
    }

    retval = sqlite3_exec(db, "INSERT INTO mytable VALUES (1, \"hello\", 2.1), (2, \"goodbye\", -0.3);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
<<<<<<< HEAD
        std::cout << "Error in previous command: " << errmsg << std::endl;
=======
        cout << "Error in previous command: " << errmsg << endl;
>>>>>>> parent of 7e1fd01... cleaning master
        sqlite3_free(errmsg);
    }

    sqlite3_stmt *s;
    const char *sql = "SELECT * FROM mytable ORDER BY id";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
<<<<<<< HEAD
        std::cout << "Error in prepareing statment." << std::endl;
=======
        cout << "Error in prepareing statment." << endl;
>>>>>>> parent of 7e1fd01... cleaning master
    }
    while(sqlite3_step(s) == SQLITE_ROW) {
        int id = sqlite3_column_int(s, 0);
        const unsigned char *val = sqlite3_column_text(s, 1);
        double x = sqlite3_column_double(s, 2);
<<<<<<< HEAD
        std::cout << "ID = " << id << ", val = " << val << ", x = " << x << std::endl;
=======
        cout << "ID = " << id << ", val = " << val << ", x = " << x << endl;
>>>>>>> parent of 7e1fd01... cleaning master
    }
    sqlite3_finalize(s);

    sqlite3_close(db);
<<<<<<< HEAD
    //end stuff from database main file

    return a.exec();
=======
    
    return 0;
>>>>>>> parent of 7e1fd01... cleaning master
}
