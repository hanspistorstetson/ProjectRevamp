#ifndef USER_H
#define USER_H

#include <vector>

class User {
    public:
        //TODO: Stub out methods for the controller to access the database
        ~User();
        static User* createUser(std::string uuid, std::string username, std::string fname, std::string lname, size_t eventid);
        static User* loadUserById(std::string userid);
        std::string getUserId();
        std::string getUsername();
        std::string getUserFname();
        std::string getUserLname();
        size_t getEventID();
        void setUsername(std::string);
        void setUserFname(std::string);
        void setUserLname(std::string);
        
    private:
        sqlite3 *db;
        User(std::string, std::string, std::string, std::string, size_t);
        std::string uuid;
        size_t eventid;
        std::string username;
        std::string fname;
        std::string lname;

};

#endif
