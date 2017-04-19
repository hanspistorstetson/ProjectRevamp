#include "sqlite3.h"
#include "database.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Database::Database() {
    int retval;
    retval = sqlite3_open("qrlogger.db", &db);
    if (retval != 0) {
        cout << "Cannot open qrlogger.db: " << sqlite3_errcode(db) << endl;
        exit(1);
    }
}

static sqlite3* Database::openDatabase() {
    if (!instance) {
        instance = new Database();
    }
    return instance->db;
}

Database::~Database() {
    sqlite3_close(db);
}
