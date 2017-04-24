#ifndef USER_H
#define USER_H

#include <vector>
#include <string>

/**
  * Built as part of the Boo QR Logger Project, a class project from the Spring 2017 Software Development I class at Stetson University.
  * User model class that creates a row in the users table and loads values into memory in an instance of this class.
  *
  * @author Hayden Estey
  */

class User {
    public:
        ~User();
        static User* createUser(std::string username, std::string fname, std::string lname, size_t eventid);
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
