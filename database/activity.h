#ifndef ACTIVITY_H
#define ACTIVITY_H
#include "checkin.h"
#include <vector>

class Activity {
    public:
	//Activity(int eventid, int id , std::string name); //is this necessary if have createActivit?y
  	static Activity* createActivity(std::string name, size_t eventid, std::string _status);//need preReqs???
    static Activity* loadActivityByID(size_t activityid);
    int getId();
	size_t getEventId();
	void setId(size_t);
	void setEventId(size_t);
//	std::vector<Checkin*> getCheckins();
//	void addCheckins(Checkin* checkin);
	void setPreReq(Activity*);
	void setActive();
	void setInactive();
	std::string getStatus();	
    
    private:
	size_t id;
//	std::vector<Checkin*> myAttendees;
	size_t eventId;
	std::vector<Activity*> myPreReqs;//where are we declaring these?
	std::string status;
	std::string name;
    Activity();
};

#endif
