#ifndef ACTIVITY_H
#define ACTIVITY_H
#include "checkin.h"
#include <vector>

class Activity {
    public:
	//Activity(int eventid, int id , std::string name); //is this necessary if have createActivit?y
  	static Activity* createActvity(std::string name, size_t eventid, std::string _status, vector<Activity*> preReqs);//need preReqs???
    static Activity* loadActivityByID(size_t activityid);
    int getId();
	int getEventId();
	void setId(int);
	void setEventId(int);
	std::vector<Checkin*> getCheckins();
	void addCheckins(Checkin* checkin);
	void setPreReq(Activity);
	void setActive();
	void setInactive();	
    
    private:
	int id;
	std::vector<Checkin*> myAttendees;
	int eventId;
	std::vector<Activity*> myPreReqs;//where are we declaring these?
	std::string status;
	std::string name;
    Activity();
};

#endif
