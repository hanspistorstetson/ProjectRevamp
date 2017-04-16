#include <iostream>
#include "sqlite3.h"
#include "event.h"
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

Event::Event() {
    int retval;
    
    retval = sqlite3_open("qrlogger.db", &db);
    if (retval != 0) {
        cout << "Cannot open qrlogger.db: " << sqlite3_errcode(db) << endl;
        exit(1);
    }
    
    cout << "Database opened." << endl;

    char* errmsg;
    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS events (eventid integer primary key, event_name text, description text, org_name text, event_status text);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating event table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
    
    retval = sqlite3_exec(db, "INSERT INTO events (event_name, description, org_name, event_status) values (\"Constructor Test\", \"Blah blah\", \"blah\", \"blah\");", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating test event in constructor: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
}

void Event::createEvent(string event_name, string desc, string organizer_name, string event_status) {
    int retval;

    sqlite3_stmt *s;
    const char *sql = "INSERT INTO events (event_name, description, org_name, event_status) VALUES (?, ?, ?, ?)";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in preparing insert statement for events " << sqlite3_errcode(db) << endl;
        return;
    }
    retval = sqlite3_bind_text(s, 1, event_name.c_str(), event_name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return;
    }
    retval = sqlite3_bind_text(s, 2, desc.c_str(), desc.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return;
    }
    retval = sqlite3_bind_text(s, 3, organizer_name.c_str(), organizer_name.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return;
    }
    retval = sqlite3_bind_text(s, 4, event_status.c_str(), event_status.size(), SQLITE_STATIC);
    if (retval != SQLITE_OK) {
        cout << "Error in binding SQL statement " << sql << endl;
        return;
    }
    if (sqlite3_step(s) != SQLITE_DONE) {
        cout << "Error executing SQL statement " << sql << ": " << sqlite3_errcode(db) << endl;
        return;
    }
}

void Event::selectExample() {
    int retval;

    sqlite3_stmt *s;
    const char* sql = "SELECT * FROM events ORDER BY eventid";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error in select statment: " << sqlite3_errmsg(db) << endl;
    }
    while (sqlite3_step(s) == SQLITE_ROW) {
        int id = sqlite3_column_int(s, 0);
        const unsigned char* event_name = sqlite3_column_text(s, 1);
        const unsigned char* desc = sqlite3_column_text(s, 2);
        const unsigned char* org_name = sqlite3_column_text(s, 3);
        const unsigned char* status = sqlite3_column_text(s, 4);

        cout << "ID = " << id << " NAME = " << event_name << " DESC = " << desc << " ORG = " << org_name << " STATUS = " << status << endl;
    }
}

Event::~Event() {
    sqlite3_close(db);
}
