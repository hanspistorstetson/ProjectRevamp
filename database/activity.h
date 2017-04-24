#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <vector>

class Checkin;

class Activity {
    public:
    Activity(size_t, std::string, size_t , std::string); //is this necessary if have createActivit?y
  	static Activity* createActivity(std::string name, size_t eventid, std::string _status);//need preReqs???
    static Activity* loadActivityById(size_t activityid);
    size_t getId();
	size_t getEventId();
//	void setId(size_t);
	void setEventId(size_t);
	std::vector<Checkin*> getCheckins();
	void addCheckins(Checkin* checkin);
	void setPreReq(Activity*);
    //void setActive();
    //void setInactive();
    void setStatus(std::string);
	std::string getStatus();	
        std::string getActivityName();
        void setActivityName(std::string);
    private:
	size_t id;
	std::vector<Checkin*> myAttendees;
	size_t eventId;
	std::vector<Activity*> myPreReqs;//where are we declaring these?
	std::string status;
	std::string name;
    ~Activity();
};

#endif
