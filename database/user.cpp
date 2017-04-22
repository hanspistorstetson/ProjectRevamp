#include "database/sqlite3.h"
#include "database/user.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

User* User::createUser(string uuid, string username, string fname, string lname, size_t eventid) {
    User *u = new User();
    return u;
}

User* User::loadUserById(size_t userid) {
    User *u = new User();
    return u;
}

User::User() {
}

User::~User() {
}

size_t User::getUserId() {
    return uuid;
}

string User::getUserName() {
    return username;
}

string User::getUserFname() {
    return fname;
}

string User::getUserLname() {
    return lname;
}

size_t User::getEventID() {
    return eventid;
}


