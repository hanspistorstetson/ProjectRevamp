#include <iostream>
#include "database/sqlite3.h"
#include "database/checkin.h"
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

Checkin::Checkin(size_t _id, size_t user_id, size_t act_id)
{
    id = _id;
    actID = act_id;
    userID = user_id;
}

Checkin* Checkin::createCheckin(size_t user_id, size_t act_id)
{
    sqlite3* db = Database::openDatabase();
    int retval;
    sqlite3_stmt* s;


    const char* sql = "SELECT * FROM users WHERE userid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing select statement for users: error code " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_int(s, 1, user_id);
    if (retval != SQLITE_OK) {
        cout << "Error binding int to SQL statement " << sql << endl;
        return NULL;
    }
    if (sqlite3_step(s) == SQLITE_DONE) {
        cout << "Check to make sure that the user exists in the database." << endl;
        return NULL;
    }

    sql = "SELECT * FROM activities WHERE activityid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing select statement for activities: error code " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_int(s, 1, (int)act_id);
    if (retval != SQLITE_OK) {
        cout << "Error binding int to SQL statement " << sql << endl;
        return NULL;
    }
    if (sqlite3_step(s) == SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << " with error code " << sqlite3_errcode(db) << endl;
        cout << "Check to make sure that the act_id exists in the database." << endl;
        return NULL;
    }

    sql = "INSERT INTO checkins(userid, activityid) values (?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing insert statement for checkin " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_int(s, 1, user_id);
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
    
    size_t checkin_id = 0;
    if (sqlite3_step(s) == SQLITE_ROW) {
        checkin_id = (size_t)sqlite3_column_int(s, 0);
    }
    sqlite3_reset(s);

    Checkin* myCheckin = new Checkin(checkin_id, user_id, act_id);
    return myCheckin;

}

Checkin* Checkin::loadCheckinById(size_t _id)
{
    sqlite3* db = Database::openDatabase();
    sqlite3_stmt* s;
    int retval;

    size_t user_id = 0;
    size_t act_id = 0;


    const char* sql = "SELECT userid, activityid FROM checkins WHERE checkinid = ?";
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
        user_id = sqlite3_column_int(s, 1);
        act_id = sqlite3_column_int(s, 2);
    }

    Checkin *ci = new Checkin(_id, user_id, act_id);
    return ci;
}

void Checkin:: setUserId(size_t userid)
{
    userID = userid;

    sqlite3* db = Database::openDatabase();
    sqlite3_stmt* s;
    int retval;

    const char* sql = "UPDATE checkins SET userid = ? WHERE checkinid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing update statement for user field in checkins: error code " << sqlite3_errcode(db) << endl;
    }
    retval = sqlite3_bind_int(s, 1, userID);
    if (retval != SQLITE_OK) {
        cout << "Error binding userid int to SQL statement " << sql << endl;
    }
    retval = sqlite3_bind_int(s, 2, id);
    if (retval != SQLITE_OK) {
        cout << "Error binding checkinid int to SQL statement " << sql << endl;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << endl;
    }
}

void Checkin:: setActivity_ID(size_t act)
{
    actID = act;

    sqlite3* db = Database::openDatabase();
    sqlite3_stmt* s;
    int retval;


    const char* sql = "UPDATE checkins SET activityid = ? WHERE checkinid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing update statement for activity field in checkins: error code " << sqlite3_errcode(db) << endl;
    }
    retval = sqlite3_bind_int(s, 1, act);
    if (retval != SQLITE_OK) {
        cout << "Error binding text to SQL statement " << sql << endl;
    }
    retval = sqlite3_bind_int(s, 2, id);
    if (retval != SQLITE_OK) {
        cout << "Error binding int to SQL statement " << sql << endl;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << endl;
    }
}

size_t Checkin::getUserId()
{
    return userID;
}

size_t Checkin::getActId()
{
    return actID;
}

size_t Checkin::getID() {
    return id;
}

bool Checkin::isCheckedIn(size_t userid, size_t activityid) {
    sqlite3* db = Database::openDatabase();
    sqlite3_stmt* s;
    int retval;

    const char *sql = "SELECT * FROM users WHERE userid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error preparing SQL statement " << sql << ", error code: " << sqlite3_errcode(db) << endl;
        return false;
    }
    retval = sqlite3_bind_int(s,1, userid);
    if (retval != SQLITE_OK) {
        cout << "Error binding int to SQL statement " << sql << endl;
        return false;
    }
    if (sqlite3_step(s) == SQLITE_DONE) {
        cout << "User does not exist in database." << endl;
        return false;
    }
    sqlite3_reset(s);

    sql = "SELECT * FROM activities WHERE activityid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error preparing SQL statement " << sql << ", error code " << sqlite3_errcode(db) << endl;
        return false;
    }
    retval = sqlite3_bind_int(s, 1, activityid);
    if (retval != SQLITE_OK) {
        cout << "Error binding int to SQL statement " << sql << endl;
        return false;
    }
    if (sqlite3_step(s) == SQLITE_DONE) {
        cout << "Activity does not exist in database." << endl;
        return false;
    }
    sqlite3_reset(s);

    sql = "SELECT * FROM checkins WHERE userid = ? and activityid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error preparing SQL statement " << sql << ", error code " << sqlite3_errcode(db) << endl;
        return false;
    }
    retval = sqlite3_bind_int(s, 1, userid);
    if (retval != SQLITE_OK) {
        cout << "Error preparing SQL statement " << sql << endl;
        return false;
    }
    retval = sqlite3_bind_int(s, 2, activityid);
    if (retval != SQLITE_OK) {
        cout << "Error preparing SQL statement " << sql << endl;
        return false;
    }
    if (sqlite3_step(s) == SQLITE_DONE) {
        cout << "There is no checkin for this user in this activity." << endl;
        return false;
    }

    return true;
}
