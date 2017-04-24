#include <iostream>
#include "database/sqlite3.h"
#include "database/checkin.h"
#include "database/activity.h"
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

Checkin::Checkin(size_t _id, string user_id, size_t act_id)
{
    this->id = _id;
    this->actID = act_id;
    this->userID = user_id;
}

Checkin* Checkin::createCheckin(string user_id, size_t act_id)
{
    sqlite3* db = Database::openDatabase();
    int retval;
    sqlite3_stmt* s;

    const char* sql = "INSERT INTO checkins (user_id, act_id) VALUES (?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing insert statement for checkin " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 1, user_id.c_str(), user_id.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    
    retval = sqlite3_bind_int(s, 2, act_id);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing sql statement " << sql << ": error code " << sqlite3_errcode(db) <<endl;
        return NULL;
    }
    sqlite3_reset(s);

    size_t checkin_id = (size_t)sqlite3_last_insert_rowid(db);
    
    Checkin* myCheckin = new Checkin(checkin_id, user_id, act_id);
    return myCheckin;

}

Checkin* Checkin::loadCheckinById(size_t _id)
{
    sqlite3 *db = Database::openDatabase();
    sqlite3_stmt *s;
    int retval;

    string user_id;
    size_t act_id = 0;


    const char *sql = "SELECT * FROM checkins WHERE checkinid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error preparing select statement for checkins " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_int(s, 1, _id);
    if (retval != SQLITE_OK) {
        cout << "Error in binding value to SQL statement " << sql << endl;
        return NULL;
    }
    if(sqlite3_step(s) == SQLITE_ROW) {
        user_id = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 1)));
        act_id = sqlite3_column_int(s, 2);
    }

    Checkin* ci = new Checkin(_id, user_id, act_id);
    return ci;
}

void Checkin:: setUser_ID(string usr)
{
    userID = usr;

    sqlite3* db = Database::openDatabase();
    sqlite3_stmt* s;
    int retval;

    const char* sql = "UPDATE chekins SET user = ? WHERE checkinid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing update statement for user field in checkins: error code " << sqlite3_errcode(db) << endl;
        return;
    }
    retval = sqlite3_bind_text(s, 1, usr.c_str(), usr.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error binding text to SQL statement " << sql << endl;
        return;
    }
    retval = sqlite3_bind_int(s, 2, id);
    if (retval != SQLITE_OK) {
        cout << "Error binding int to SQL statement " << sql << endl;
        return;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << endl;
        return;
    }
}

void Checkin:: setActivity_ID(size_t act)
{
    actID = act;

    sqlite3* db = Database::openDatabase();
    sqlite3_stmt* s;
    int retval;


    const char* sql = "UPDATE chekins SET act = ? WHERE checkinid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing update statement for activity field in checkins: error code " << sqlite3_errcode(db) << endl;
        return;
    }
    retval = sqlite3_bind_int(s, 1, act);
    if (retval != SQLITE_OK) {
        cout << "Error binding text to SQL statement " << sql << endl;
        return;
    }
    retval = sqlite3_bind_int(s, 2, id);
    if (retval != SQLITE_OK) {
        cout << "Error binding int to SQL statement " << sql << endl;
        return;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << endl;
        return;
    }
}

Checkin::~Checkin()
{

}

string Checkin::getUserId()
{
    return userID;
}


size_t Checkin::getActId()
{
    return actID;
}

size_t Activity:: getId() {
    return id;
}
