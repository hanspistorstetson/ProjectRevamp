#ifndef CHECKIN_H
#define CHECKIN_H

#include <vector>
#include "user.h"
#include "event.h"
#include "database.h"

class Activity;

class Checkin {
    public:
        static Checkin* createCheckin(User*, Activity*);
        static Checkin* loadCheckin(size_t);
        size_t getUserId();
        void setUserId(size_t);
        size_t getActId();
        void setActId(size_t);
        User* getAttendee();
        Activity* getActivity();
        bool isCheckedIn();
        ~Checkin();
    private:
        bool checkedIn;
        User* attendee;
        Activity* activity;
        size_t userID;
        size_t actID;
        Checkin();


};
#endif
