#include "database/sqlite3.h"
#include "database/database.h"
#include <iostream>
#include <cstdlib>
#include "database/event.h"
#include <cstring>

using namespace std;
/** 
  * Built as part of the Boo QR Logger Project, a class project from the Spring 2017 Software Development I class at Stetson University.
  * Singleton Database class that opens a .db file through a static method, creates 5 tables inside of the file.
  *
  * @author Hayden Estey
  */

Database* Database::instance = 0;

Database::Database() {
    int retval;
    retval = sqlite3_open("boo.db", &db);
    if (retval != 0) {
        cout << "Cannot open boo.db: " << sqlite3_errcode(db) << endl;
        exit(1);
    }
    
    //Creating tables

    char* errmsg;
    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS events (eventid integer primary key, event_name text, description text, org_name text, event_status text);", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating event table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }
    
    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS users (userid integer primary key, uuid text, username text, fname text, lname text, eventid int, FOREIGN KEY(eventid) REFERENCES events(eventid));", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating users table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }

    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS activities (activityid integer primary key, name text, eventid int, status text, FOREIGN KEY (eventid) REFERENCES events(eventid));", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating activites table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }

    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS prerequisites (activityid integer, prereqid integer, FOREIGN KEY(activityid) REFERENCES activities(activityid), FOREIGN KEY(prereqid) REFERENCES activities(activityid));", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {
        cout << "Error creating prereq table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }

    retval = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS checkins (checkinid integer PRIMARY KEY, userid int, activityid int, FOREIGN KEY(userid) REFERENCES users(userid), FOREIGN KEY(activityid) REFERENCES activities(activityid));", NULL, NULL, &errmsg);
    if (retval != SQLITE_OK) {

        cout << "Error creating checkins table: " << errmsg << endl;
        sqlite3_free(errmsg);
    }

    //Make a default event if it does not exist
    
    sqlite3_stmt* s;
    const char* sql = "SELECT eventid FROM events";
    retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
    if (retval != SQLITE_OK) {
        cout << "Error preparing SQL statement " << sql << " (to create default event): error code " << sqlite3_errcode(db) << endl;
        return;
    }
    if (sqlite3_step(s) == SQLITE_DONE) {
        cout << "Creating a default event." << endl;
        sqlite3_reset(s);
        sql = "INSERT INTO events (event_name, description, org_name, event_status) values (\"Naked Mole Rat Exhibition\", \"An exhibition on Naked Mole Rats\", \"The Joshua Eckroth Foundation\", \"Upcoming\")";
        retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
        if (retval != SQLITE_OK) {
            cout << "Error preparing SQL statement " << sql << ", error code: " << sqlite3_errcode(db) << endl;
            return;
        }
        if (sqlite3_step(s) != SQLITE_DONE) {
            cout << "Error executing SQL statement " << sql << ", error code: " << sqlite3_errcode(db) << endl;
            return;
        }
    } else {
        sqlite3_reset(s);
    }
}

sqlite3* Database::openDatabase() {
    if (!instance) {
        instance = new Database;
    }
    return instance->db;
}

void Database::closeDatabase() {
    if(instance) { delete instance; }
}

Database::~Database() {
    sqlite3_close(db);
}


