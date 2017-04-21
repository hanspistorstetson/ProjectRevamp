#include <iostream>
#include "sqlite3.h"
#include "activity.h"
#include "database.h"
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

Activity::Activity(size_t _id, string act_name, size_t event_id, string _status) {
    this->id = _id;
    this->name = act_name;
    this->eventId = event_id;
    this->status = _status;
}

 Activity* Activity::createActivity(string activity_name, size_t event_id, string activity_status) {
    int retval;
     sqlite3* db = Database::openDatabase();
    sqlite3_stmt *s;
    const char *sql = "INSERT INTO activityTable (activity_name, event_id, activity_status) VALUES (?, ?, ?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing insert statement for activity " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 1, activity_name.c_str(), activity_name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }

   retval = sqlite3_bind_int(s, 2, event_id);

   retval = sqlite3_bind_text(s, 3, activity_status.c_str(), activity_status.size(), SQLITE_STATIC);
   if (retval != SQLITE_OK) {
       cout << "Error in binding SQL statement " << sql << endl;
       return NULL;
   }
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db) << endl;
        return NULL;
    }

    //select statement to get the event id
    sql = "SELECT activityid FROM activities WHERE activity_name = ? AND event_id = ? AND activity_status = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error preparing select statement for events " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 1, activity_name.c_str(), activity_name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    retval = sqlite3_bind_int(s, 2, event_id);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }

    retval = sqlite3_bind_text(s, 3, activity_status.c_str(), activity_status.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    //TODO: Remember to write a test case for this! Should only get one row from the select statement...
    size_t act_id = 0;
    if (sqlite3_step(s) == SQLITE_ROW) {
        act_id = sqlite3_column_int(s, 0);
    }

	//needs to return pointer to the activity created
    Activity* a = new Activity(act_id, activity_name , event_id , activity_status);

	return a;
}
 Activity* Activity::loadActivityById(size_t id) {
     sqlite3 *db = Database::openDatabase();
     int retval;
     sqlite3_stmt *s;
     //const unsigned char* name;
     //const unsigned char* desc;
     //const unsigned char* org;
     //const unsigned char* status;
     string name, status;
     size_t eventId = -1;


     const char *sql = "SELECT * FROM activities WHERE activityid = ?";
     retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
     if (retval != SQLITE_OK) {
         cout << "Error preparing select statement for events " << sqlite3_errcode(db) << endl;
         return NULL;
     }
     retval = sqlite3_bind_int(s, 1, id);
     if (retval != SQLITE_OK) {
         cout << "Error in binding value to SQL statement " << sql << endl;
         return NULL;
     }
     if(sqlite3_step(s) == SQLITE_ROW) {
         name = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 1)));
         eventId = sqlite3_column_int(s, 2);
         status = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 3)));
     }

     Activity *a = new Activity(id, name, eventId, status);
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
void  Activity:: setId(size_t newid) {
	id = newid;
}
void Activity:: setEventId(size_t newid) {
	eventId = newid;
}

vector<Checkin*> Activity:: getCheckins() {
	return myAttendees;
}

string Activity:: getName() {
	return name;
}
void Activity:: setName(string newname) {
    this->name = newname;
    sqlite3* db = Database::openDatabase();
    int retval;

    sqlite3_stmt* s;
    const char* sql = "UPDATE activities set activity_name = ? WHERE activityid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing update statement for updating event_name field in events table " << sqlite3_errcode(db) << endl;
        return;
    }
    retval = sqlite3_bind_int(s, 2, this->id);
    if (retval != SQLITE_OK) {
        cout << "Error in binding int to SQL statement " << sql << endl;
        return;
    }
    retval = sqlite3_bind_text(s, 1, name.c_str(), name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding text to SQL statment " << sql << endl;
        return;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement << " << sql << endl;
        return;
    }
    sqlite3_reset(s);
}
Activity::~Activity() {

}
