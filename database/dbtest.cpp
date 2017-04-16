#include <iostream>
#include "sqlite3.h"
#include "event.h"
#include "user.h"

using namespace std;

int main() {
    Event event_model;
    event_model.createEvent("Test Name", "Test Description", "Test Organizer", "Test Status");
    event_model.selectExample();
    
    User user_model;

    return 0;
}
