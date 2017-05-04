#include <iostream>
#include "database/user.h"
#include "database/dbtest.h"
#include "database/event.h"
#include "database/activity.h"
#include "database/checkin.h"
#include <vector>
using namespace std;

/**
  * Built for the Boo QR Logger Project, a class project from the Spring 2017 Software Development I class at Stetson University.
  * Database & Model testing class.
  * 
  * @author Hayden Estey
  */

void dbtest::testCreating() {

    cout << "TEST CREATING: " << endl;
    cout << endl;

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
    cout<<"UUID: "<<user->getUserId()<<endl;

    Activity* act = Activity::createActivity("Test Activity Name", 1, "Test Activity Status");
    cout << act->getActivityName() << " ,"<< act->getEventId() << ", " << act->getStatus() << endl;
    act->setActivityName("Spit distance contest");
    cout << act->getActivityName() << endl;
    act->setEventId(15);
    cout << act->getEventId() << endl;
    act->setStatus("Exhibiting now!");
    cout << act->getStatus() << endl;
    cout << act->getId() <<"---activtity id"<< endl;

    vector<Activity*> prereqs;
    prereqs.push_back(act);
    Activity* act2 = Activity::createActivity("Activity with Prereqs", 1, "Active", prereqs);
    vector<Activity*> act2Prereqs = act2->getPrereqs();
    cout << act2Prereqs[0]->getActivityName() << endl;

    Checkin* checkin = Checkin::createCheckin("e635ec8d-f8bf-4e4e-b9dd-2a51dc8bebb8", 1);
    cout << checkin->getUserId() << " ,"<< checkin->getActId()<< endl;
    checkin->setActivity_ID(1);
    cout << checkin->getActId() << endl;
    checkin->setUser_ID("Plante");
    cout << checkin->getUserId() << endl;
    cout << checkin->getID() << endl;

    delete event;
    delete user;
    delete act;
    delete checkin;
}

void dbtest::testLoading() {

    cout << "TEST LOADING: " << endl;
    cout << endl;

    Event* event = Event::loadEventById(1);
    cout << event->getEventName() << " " << event->getEventDesc() << " " << event->getOrgName() << " " << event->getStatus() << endl;
   /* User* user = User::loadUserById();
    cout << user->getUsername() << " " << user->getUserFname() << " " << user->getUserLname() << endl;
*/
    Activity* act = Activity::loadActivityById(1);
    cout << act->getActivityName() << ", " << act->getEventId() << ", " << act->getStatus() << endl;
    
    Activity* act2 = Activity::loadActivityById(2);
    vector<Activity*> prereqs = act2->getPrereqs();
    cout << prereqs[0]->getActivityName() << endl;

    Checkin* checkin = Checkin::loadCheckinById(1);
    cout << checkin->getUserId() << ", " << checkin->getActId() << endl;

    cout << "Matches to spit: "<<endl;
    std::vector<Activity*> actmatches = Activity::searchByName("Spit");
        for(size_t i = 0; i < actmatches.size();i++) {
            cout<<actmatches[i]->getActivityName()<<endl;
        }
        cout<<"All Activities: "<<endl;
    std::vector<Activity*> all_acts = Activity::getAllActivities();
            for(size_t i = 0; i < all_acts.size();i++) {
                cout<<all_acts[i]->getActivityName()<<endl;
        }

       cout << "Matches to Cena: "<<endl;
       std::vector<User*> usermatches = User::searchByLastName("Cena");
            for(size_t i = 0; i < usermatches.size();i++) {
                    cout<<usermatches[i]->getUserLname()<<endl;

            }
       cout<<"All Users for event: "<<endl;
       std::vector<User*> all_users = User::getAllUsers();
       for(size_t i = 0; i < all_users.size();i++) {
                        cout<<all_users[i]->getUserFname()<<endl;
              }

    cout<<"ENDING"<<endl;
    delete event;
    delete act;
    //delete user;
    delete checkin;

}
