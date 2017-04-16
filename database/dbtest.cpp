#include <iostream>
#include "sqlite3.h"
#include "event.h"

using namespace std;

int main() {
    Event event_model;
    event_model.createEvent("Test Name", "Test Description", "Test Organizer", "Test Status");
    event_model.selectExample();

    return 0;
}
