#ifndef CHECKIN_H
#define CHECKIN_H

#include <vector>
#include "database/user.h"
#include "database/event.h"
#include "database/database.h"

class Activity;

class Checkin {
    public:
        static Checkin* createCheckin(std::string, size_t);
        static Checkin* loadCheckinById(size_t);
        std::string getUserId();
        size_t getActId();
        bool isCheckedIn();
        void setUser_ID(std::string);
        void setActivity_ID(size_t);
        ~Checkin();
    private:
        size_t id;
        bool checkedIn;
        std::string userID;
        size_t actID;
        Checkin(size_t, std::string, size_t);
};
#endif
