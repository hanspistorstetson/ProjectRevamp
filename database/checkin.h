#ifndef CHECKIN_H
#define CHECKIN_H

#include <vector>
#include "user.h"
#include "event.h"
#include "activity.h"

class Checkin {
    public:
        Checkin();
        Checkin(User, Activity);
        void incrementCount(Activity);
        bool isCheckedIn();
    private:
        bool checkedIn;
        std::vector<User> Attendees;
};
#endif
