#include <iostream>
#include "sqlite3.h"
#include "event.h"
#include "user.h"
#include "dbtest.h"

using namespace std;

void dbtest::testCreating() {
    Event* event = Event::createEvent("Test Name", "Test Description", "Test Org", "Test Status");
    cout << event->getEventName() << " " << event->getEventDesc() << " " << event->getOrgName() << " " << event->getStatus() << endl;
    event->setEventName("Naked Mole Rate Exhibition");
    cout << event->getEventName() << endl;
    event->setOrgName("The Eckroth Foundation for Naked Mole Rat Research");
    cout << event->getOrgName() << endl;
    event->setStatus("Exhibiting now!");
    cout << event->getStatus() << endl;
    cout << event->getEventId() << endl;
    User* user = User::createUser("test id", "test@test.test", "test", "test", event->getEventId());
    //Activity* activity_model = Activity::createActivity("activity name", 1, "test status"); //add prereqs too

    delete event;
    delete user;
}

void dbtest::testLoading() {
    Event* event = Event::loadEventById(1);
    cout << event->getEventName() << " " << event->getEventDesc() << " " << event->getOrgName() << " " << event->getStatus() << endl;
    User* user = User::loadUserById("test id");
    cout << user->getUsername() << " " << user->getUserFname() << " " << user->getUserLname() << endl;

    delete event;
    delete user;
}
