#ifndef USER_H
#define USER_H

#include <vector>

class user {
    public:
        //TODO: Stub out methods for the controller to access the database
        User();
        ~User();

    private:
        sqlite3 *db;
};

#endif
