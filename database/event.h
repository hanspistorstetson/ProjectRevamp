#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>

/**
  * Part of the Boo QR Logger Project, a class project for the Spring 2017 Software Development I class at Stetson University.
  * Event model class creates a row inside of the events table in the database, and then loads the field values into memory in an instance of this class.
  *
  * @author Hayden Estey
  */

class Event {
    public:
        ~Event();
        static Event* createEvent(std::string event_name, std::string desc, std::string organizer_name, std::string event_status);
        static Event* loadEventById(size_t eventid);
        std::string getEventName();
        std::string getEventDesc();
        std::string getOrgName();
        std::string getStatus();
        size_t getEventId();
        void setEventName(std::string name);
        void setEventDesc(std::string desc);
        void setOrgName(std::string org_name);
        void setStatus(std::string status);
        
    private:
        Event(size_t id, std::string event_name, std::string _desc, std::string org_name, std::string _status);
        size_t eventid;
        std::string name;
        std::string desc;
        std::string org;
        std::string status;
};

#endif
