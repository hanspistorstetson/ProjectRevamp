#ifndef CHECKIN_H
#define CHECKIN_H

#include <vector>
#include "database/user.h"
#include "database/event.h"
#include "database/database.h"

class Activity;

class Checkin {
    public:
        static Checkin* createCheckin(size_t, size_t);
        static Checkin* loadCheckinById(size_t);
        std::string getUUID();
        size_t getUserId();
        size_t getActId();
        static bool isCheckedIn(size_t, size_t);
        size_t getID();
        void setUserId(size_t);
        void setActivity_ID(size_t);
        static std::vector<User*> getUsersbyActivityId(size_t);
        static std::vector<Activity*> getActivitiybyUserId(size_t);

    private:
        size_t id;
        size_t userID;
        size_t actID;
        Checkin(size_t, size_t, size_t);
};
#endif
