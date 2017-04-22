#include <iostream>
#include "sqlite3.h"
#include "user.h"
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

User::User() {
}

User::~User() {
    sqlite3_close(db);
}
