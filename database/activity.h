#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <vector>

class Checkin;

class Activity {
    public:
    Activity(size_t, std::string, size_t , std::string);
  	static Activity* createActivity(std::string name, size_t eventid, std::string _status);//need preReqs???
    static Activity* loadActivityById(size_t activityid);
    size_t getId();
	size_t getEventId();
	void setEventId(size_t);
	std::vector<Checkin*> getCheckins();
	void addCheckins(Checkin* checkin);
	void setPreReq(Activity*);
    void setStatus(std::string);
	std::string getStatus();	
    std::string getActivityName();
    void setActivityName(std::string);
    ~Activity();

    private:
	size_t id;
	std::vector<Checkin*> myAttendees;
	size_t eventId;
    std::vector<Activity*> myPreReqs;
	std::string status;
	std::string name;
};

#endif
