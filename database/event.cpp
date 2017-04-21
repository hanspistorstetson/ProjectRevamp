#include <iostream>
#include "sqlite3.h"
#include "event.h"
#include <cstdlib>
#include <string>
#include <cstring>
#include "database.h"

using namespace std;

Event::Event(size_t id, string event_name, string _desc, string org_name, string _status) {
    this->eventid = id;
    this->name = event_name;
    this->desc = _desc;
    this->org = org_name;
    this->status = _status;
}

Event* Event::createEvent(string event_name, string desc, string organizer_name, string event_status) {
    sqlite3 *db = Database::openDatabase();
    int retval;
    
    sqlite3_stmt *s;
    const char *sql = "INSERT INTO events (event_name, description, org_name, event_status) VALUES (?, ?, ?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing insert statement for events " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 1, event_name.c_str(), event_name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 2, desc.c_str(), desc.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 3, organizer_name.c_str(), organizer_name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 4, event_status.c_str(), event_status.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    
    //select statement to get the event id
    sql = "SELECT eventid FROM events WHERE event_name = ? AND description = ? AND org_name = ? AND event_status = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error preparing select statement for events " << sqlite3_errcode(db) << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 1, event_name.c_str(), event_name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 2, desc.c_str(), desc.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 3, organizer_name.c_str(), organizer_name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    retval = sqlite3_bind_text(s, 4, event_status.c_str(), event_status.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return NULL;
    }
    //TODO: Remember to write a test case for this! Should only get one row from the select statement...
    size_t id = 0;
    if (sqlite3_step(s) == SQLITE_ROW) {
        id = sqlite3_column_int(s, 0);
    }

    Event *e = new Event(id, event_name, desc, organizer_name, event_status);
    return e;
}

Event* Event::loadEventById(size_t id) {
    sqlite3 *db = Database::openDatabase();
    int retval;
    sqlite3_stmt *s;
    //const unsigned char* name;
    //const unsigned char* desc;
    //const unsigned char* org;
    //const unsigned char* status;
    string name, desc, org, status;

    const char *sql = "SELECT * FROM events WHERE eventid = ?";
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
        desc = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 2)));
        org = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 3)));
        status = string(reinterpret_cast<const char*>(sqlite3_column_text(s, 4)));
    }

    Event *e = new Event(id, name, desc, org, status);
    return e;
}

string Event::getEventName() {
    return this->name;
}

string Event::getEventDesc() {
    return this->desc;
}

string Event::getOrgName() {
    return this->org;
}

string Event::getStatus() {
    return this->status;
}

void Event::setEventName(string _name) {
    this->name = _name;
    sqlite3* db = Database::openDatabase();
    int retval;

    sqlite3_stmt* s;
    const char* sql = "UPDATE events set event_name = ? WHERE eventid = ?";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing update statement for updating event_name field in events table " << sqlite3_errcode(db) << endl;
        return;
    }
    retval = sqlite3_bind_int(s, 2, this->eventid);
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

Event::~Event() {
}
