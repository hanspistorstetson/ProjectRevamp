#include "sqlite3.h"
#include "database.h"
#include <iostream>
#include <cstdlib>

using namespace std;
Database* Database::instance = 0;

Database::Database() {
    int retval;
    retval = sqlite3_open("qrlogger.db", &db);
    if (retval != 0) {
        cout << "Cannot open qrlogger.db: " << sqlite3_errcode(db) << endl;
        exit(1);
    }
    
    //Creating tables

    char* errmsg;
    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS events (eventid integer primary key, event_name text, description text, org_name text, event_status text);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating event table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
    
    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS users (uuid text PRIMARY KEY, username text, fname text, lname text, eventid int, FOREIGN KEY(eventid) REFERENCES events(eventid));", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating users table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }

    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS activities (activityid integer primary key, name text, eventid int, status text);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating activites table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }

    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS prerequisites (activityid integer, prereqid integer);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating prereq table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }

    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS checkins (checkinid integer primary key, uuid text, status text);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating checkins table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
}
sqlite3* Database::openDatabase() {
    if (!instance) {
        instance = new Database();
    }
    return instance->db;
}

Database::~Database() {
    sqlite3_close(db);
    delete instance;
}
