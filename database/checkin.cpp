#include <iostream>
#include "sqlite3.h"
#inclued "checkin.h"
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

Checkin::Checkin() {
    int retval;

    retval = sqlite3_open("qrlogger.db", &db);
    if (retval != 0) {
        cout << "Cannot open qrlogger.db: " << sqlite3_errcode(db) << endl;
        exit(1);
    }

    cout << "Database opened." << endl;

    char* errmsg;
    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS activityTable (name text, eventid int, actvityid int, status text);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating event table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
    retval = sqlite3_exec(db, "INSERT INTO activityTable (\"test\", 1, 3, \"active\");", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating test event in constructor: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
}

