#ifndef PARTICIPANT_H_
#define PARTICIPANT_H_
#include "Time.h"
using namespace std;

class Participant {
private:
	string name;
	Time Zeit;
	static int valid_Participants;

public:
	Participant(string name = "", Time Zeit = Time(0,0,0));
	~Participant();
	void give_name(string n);
	void give_time(Time t);
	string return_name();
	Time return_time();
	long justseconds();
	string ausgabe() const;
};

#endif
