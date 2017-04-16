#include <iostream>
#include "sqlite3.h"
#include "user.h"
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

User::User() {
    int retval;

    retval = sqlite3_open("qrlogger.db", &db);
    if (retval != 0) {
        cout << "Cannot open qrlogger.db: " << sqlite3_errorcode(db) << endl;
        exit(1);
    }

    cout << "Database opened." << endl;

    char* errmsg;
    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS users (uuid text, username text, email text, eventid int, FOREIGN KEY(eventid) REFERENCES events(eventid));", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating users table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
}

User::~User() {
    sqlite3_close(db);
}
