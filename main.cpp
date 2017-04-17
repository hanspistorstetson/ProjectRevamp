#include "mainwindow.h"
#include <QApplication>
#include <cstdlib>
#include <iostream>
#include "sqlite3.h"
#include <cstring>

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

    char* errmsg;
    retval = sqlite3_exec(db, "CREATE TABLE mytable (id int, val text, x double);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        std::cout << "Error in previous command: " << errmsg << std::endl;
        sqlite3_free(errmsg);
    }

    retval = sqlite3_exec(db, "INSERT INTO mytable VALUES (1, \"hello\", 2.1), (2, \"goodbye\", -0.3);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        std::cout << "Error in previous command: " << errmsg << std::endl;
        sqlite3_free(errmsg);
    }

    sqlite3_stmt *s;
    const char *sql = "SELECT * FROM mytable ORDER BY id";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        std::cout << "Error in prepareing statment." << std::endl;
    }
    while(sqlite3_step(s) == SQLITE_ROW) {
        int id = sqlite3_column_int(s, 0);
        const unsigned char *val = sqlite3_column_text(s, 1);
        double x = sqlite3_column_double(s, 2);
        std::cout << "ID = " << id << ", val = " << val << ", x = " << x << std::endl;
    }
    sqlite3_finalize(s);

    sqlite3_close(db);
    //end stuff from database main file

    return a.exec();
}
