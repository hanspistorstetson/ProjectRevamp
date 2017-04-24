#ifndef DATABASE_H
#define DATABASE_H

#include "database/sqlite3.h"

/**
  * Built as part of the Boo QR Logger Project, a class project from the Spring 2017 Software Development I class at Stetson University.
  * Singleton Database class that opens a .db file through a static method, creates 5 tables inside of the file.
  *
  * @author Hayden Estey
  */

class Database {
    public:
        static sqlite3* openDatabase();
        static void closeDatabase();

    private:
        sqlite3 *db;
        Database();
        ~Database();
        static Database* instance;
};
#endif
