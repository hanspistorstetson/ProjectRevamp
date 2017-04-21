#include <iostream>
#include "sqlite3.h"
#include "checkin.h"
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

Checkin::Checkin()
{
}

/*
Checkin::~Checkin()
{
    delete cin;
}
*/

static Checkin* Checkin::createCheckin(User* user, Activity* act)
{
    int retval;
    sqlite3* db = Database::openDatabase();
    attendee = user;
    activity = act;

    sqlite3_stmt *s;
    const char *sql = "INSERT INTO checkinTable (user, act) VALUES (?, ?, ?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing insert statement for activity " << sqlite3_errcode(db) << endl;
        return;
    }
    retval = sqlite3_bind_text(s, 1, activity_name.c_str(), activity_name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return;
    }
    retval = sqlite3_bind_text(s, 2, activity_status.c_str(), activity_status.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return;
    }

   retval = sqlite3_bind_int(s, 3, event_id);

    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return;
    }
    //needs to return pointer to the activity created
    Checkin* myCheckin = new Checkin();
    return myCheckin;

}

void Checkin::setUserId(size_t uid)
{
    userID = uid;
}

size_t Checkin::getUserId()
{
    return userID;
}

void Checkin::setActivity(size_t aid)
{
    actID = aid;
}

size_t Checkin::getActId()
{
    return actID;
}
