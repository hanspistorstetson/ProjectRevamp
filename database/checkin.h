#ifndef CHECKIN_H
#define CHECKIN_H

#include <vector>
#include "user.h"
#include "event.h"
#include "activity.h"

class Activity;

class Checkin {
    private:
        bool checkedIn;
        User* attendee;
        Activity* activity;
        size_t userID;
        size_t actID;
        Checkin();
    public:
        static Checkin* makeCheckin(User*, Activity*);
        static Checkin* loadCheckin(size_t);
        size_t getUserId();
        void setUserId(size_t);
        size_t getActId();
        void setActId();
        User* getAttendee();
        Activity* getActivity();
        bool isCheckedIn();
        ~Checkin();

};
#endif
