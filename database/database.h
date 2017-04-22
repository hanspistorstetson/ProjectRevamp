#ifndef DATABASE_H
#define DATABASE_H

#include "sqlite3.h"


class Database {
    public:
        static sqlite3* openDatabase();
        ~Database();

    private:
        sqlite3 *db;
        Database();
        static Database* instance;
};
#endif
