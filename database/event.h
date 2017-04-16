#ifndef EVENT_H
#define EVENT_H

#include <vector>

class Event {
    public:
        //TODO: Stub out all the methods for the controller to access the database
        Event();
        ~Event();
        void createEvent(std::string event_name, std::string desc, std::string organizer_name, std::string event_status);
        void selectExample();

    private:
        sqlite3 *db;
};

#endif
