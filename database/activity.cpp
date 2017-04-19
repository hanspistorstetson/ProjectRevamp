#include <iostream>
#include "sqlite3.h"
#include "activity.h"
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

Activity::Activity() {
    int retval;

    retval = sqlite3_open("qrlogger.db", &db); //need the global db to use here;
    if (retval != 0) {
        cout << "Cannot open qrlogger.db: " << sqlite3_errcode(db) << endl;
        exit(1);
    }
    
    cout << "Database opened." << endl;

    char* errmsg;
    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS activityTable (activity_id int, name text, eventid int, status text);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating event table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
    
    retval = sqlite3_exec(db, "INSERT INTO activityTable (\"test\", \"active\", 1);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating test event in constructor: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
}

static Activity* Activity::createActivity(string activity_name, size_t event_id, string activity_status) {
    int retval;

    sqlite3_stmt *s;
    const char *sql = "INSERT INTO activityTable (activity_name, event_id, activity_status) VALUES (?, ?, ?, ?)";
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
	Activity* a = new Activity();
	return a;
}



void Activity::setActive() {
	status = "active";
}

void Activity::setInactive() {
	status = "inactive";
}
string Activity::getStatus() {
	return status;
}
size_t Activity:: getId() {
	return id;
}

size_t Activity:: getEventId() {
	return eventId;
}
void  Activity:: setId(int newid) {
	id = newid;
}
void Activity:: setEventId(int newid) {
	eventId = newid;
}

vector<Checkin> Activity:: getCheckins() {
	return myAttendees;
}

string Activity:: getName() {
	return name;
}
void Activity:: setName(string newname) {
	name = newname;
}
