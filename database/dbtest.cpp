#include <iostream>
#include "sqlite3.h"
#include "event.h"
#include "user.h"
#include "activity.h"

using namespace std;

int main() {
    Event* event_model = Event::createEvent("Test Name", "Test Description", "Test Org", "Test Status");
    event_model.selectExample();    
    User* user_model = User::createEvent("test id", "test@test.test", "test", "test", "12345");
    return 0;
}
