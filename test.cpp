#include "database/dbtest.h"
#include "database/database.h"

int main() {
    
    Database::openDatabase();
    dbtest::testCreating();
    dbtest::testLoading();

    return 0;
}
