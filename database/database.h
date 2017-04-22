#ifndef DATABASE_H
#define DATABASE_H

#include "database/sqlite3.h"


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
