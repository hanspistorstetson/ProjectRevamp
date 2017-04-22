#ifndef USER_H
#define USER_H

#include <vector>
#include <string>

class User {
    public:
        ~User();
        static User* createUser(size_t uuid, std::string username, std::string fname, std::string lname, size_t eventid);
        static User* loadUserById(size_t userid);
        size_t getUserId();
        std::string getUsername();
        std::string getUserFname();
        std::string getUserLname();
        size_t getEventID();
        void setUsername(std::string);
        void setUserFname(std::string);
        void setUserLname(std::string);
        
    private:
        User(size_t, std::string, std::string, std::string, size_t);
        size_t uuid;
        size_t eventid;
        std::string username;
        std::string fname;
        std::string lname;

};

#endif
