#include <iostream>
#include "database/user.h"
#include "database/dbtest.h"
#include "database/event.h"

using namespace std;

/**
  * Built for the Boo QR Logger Project, a class project from the Spring 2017 Software Development I class at Stetson University.
  * Database & Model testing class.
  * 
  * @author Hayden Estey
  */

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
    User* user = User::createUser("test@test.test", "test", "test", event->getEventId());
    user->setUsername("John Cena");
    user->setUserFname("John");
    user->setUserLname("Cena");
    //Activity* activity_model = Activity::createActivity("activity name", 1, "test status"); //add prereqs too

    delete event;
    delete user;
}

void dbtest::testLoading() {
    Event* event = Event::loadEventById(1);
    cout << event->getEventName() << " " << event->getEventDesc() << " " << event->getOrgName() << " " << event->getStatus() << endl;
    User* user = User::loadUserById(1);
    cout << user->getUsername() << " " << user->getUserFname() << " " << user->getUserLname() << endl;

    delete event;
    delete user;
}
