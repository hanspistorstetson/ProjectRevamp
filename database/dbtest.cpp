#include <iostream>
#include "sqlite3.h"
#include "event.h"

using namespace std;

int main() {
    Event* event = Event::createEvent("Test Name", "Test Description", "Test Org", "Test Status");
    //User* user_model = User::createUser("test id", "test@test.test", "test", "test", "12345");
    //Activity* activity_model = Activity::createActivity("activity name", 1, "test status"); //add prereqs too
    return 0;
}
