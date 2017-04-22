#ifndef USER_H
#define USER_H

#include <vector>
#include <string>

class User {
    public:
        ~User();
        static User* createUser(std::string uuid, std::string username, std::string fname, std::string lname, size_t eventid);
        static User* loadUserById(size_t userid);
        size_t getUserId();
        std::string getUserName();
        std::string getUserFname();
        std::string getUserLname();
        size_t getEventID();

    private:
        User();
        size_t uuid;
        size_t eventid;
        std::string username;
        std::string fname;
        std::string lname;

};

#endif
