#include <iostream>
#include "sqlite3.h"
#include "user.h"
#include <cstdlib>
#include <string>
#include <cstring>
#include "database.h"

using namespace std;

User::User(string _uuid, string _username, string _fname, string _lname, size_t _eventid) {
    this->uuid = _uuid;
    this->username = _username;
    this->fname = _fname;
    this->lname = _lname;
    this->eventid = _eventid;
}

User* User::createUser(string uuid, string username, string fname, string lname, size_t eventid) {
    sqlite3* db = Database::openDatabase();
    int retval;
    sqlite3_stmt* s;

    const char* sql = "SELECT eventid FROM events WHERE eventid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing select statement for events: error code " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_int(s, 1, eventid);
    if (retval != SQLITE_OK) {
        cout << "Error binding int to SQL statement " << sql << endl;
        return NULL;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << " with error code " << sqlite3_errcode(db) << endl;
        cout << "Check to make sure that the event exists in the database." << endl;
        return NULL;
    }
    
    sql = "INSERT INTO users (uuid, username, fname, lname, eventid) values (?, ?, ?, ?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing insert statement for users: error code " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 1, uuid.c_str(), uuid.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error binding uuid text to SQL statement " << sql << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 2, username.c_str(), username.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error binding username text to SQL statement " << sql << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 3, fname.c_str(), fname.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error binding fname text to SQL statement " << sql << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 4, lname.c_str(), lname.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error binding lname text to SQL statement " << sql << endl;
        return NULL;
    }
    retval = sqlite3_bind_int(s, 5, eventid);
    if (retval != SQLITE_OK) {
        cout << "Error binding int to SQL statement " << sql << endl;
        return NULL;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing sql statement " << sql << ": error code " << sqlite3_errcode(db) <<endl;
        return NULL;
    }
    sqlite3_reset(s);

    User* u = new User(uuid, username, fname, lname, eventid);
    return u;
}



User::~User() {
}
