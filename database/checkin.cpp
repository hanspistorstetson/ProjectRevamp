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

Checkin* Checkin::createCheckin(User* user, Activity* act)
{
    int retval;
    sqlite3* db = Database::openDatabase();
    /*
    attendee = new User();
    attendee = user;
    activity = new Activity();
    activity = act;
    */
    sqlite3_stmt *s;
    const char *sql = "INSERT INTO checkinTable (user, act) VALUES (?, ?, ?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing insert statement for activity " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 1, user->getUserFname().c_str(), user->getUserFname().size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    /*
   retval = sqlite3_bind_text(s, 2, act->getName().c_str(), act->getName().size(), SQLITE_STATIC);

    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    */
    //needs to return pointer to the checkin created
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

void Checkin::setActId(size_t aid)
{
    actID = aid;
}

size_t Checkin::getActId()
{
    return actID;
}
