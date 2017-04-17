#ifndef ACTIVITY_H
#define ACTIVITY_H
#include "checkin.h"
#include <vector>

class Activity {
    public:
	//Activity(int eventid, int id , std::string name); //is this necessary if have createActivit?y
  	static Activity* createActvity(std::string , int event, int id , std::string _status);//need preReqs???
    static Activity* loadActivityByID(size_t activityid);
    int getId();
	int getEventId();
	void setId(int);
	void setEventId(int);
	std::vector<Checkin*> getCheckins();
//	void addToCheckins(//.....
///	void setPreReq(Activity);
	
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
