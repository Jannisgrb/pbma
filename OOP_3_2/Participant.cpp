#include <iostream>
#include "Participant.h"
using namespace std;

int Participant::valid_Participants = 0;

Participant::Participant(string name, Time Zeit){
	this->name = name;
	this->Zeit = Zeit;
	valid_Participants += 1;
}

Participant::~Participant(){
	valid_Participants -=1;
}

void Participant::give_name(string n){
	name = n;
}

void Participant::give_time(Time t){
	Zeit = t;
}

string Participant::return_name(){
	return name;
}

Time Participant::return_time(){
	return Zeit;
}

long Participant::justseconds(){
	return Zeit.hour() * 3600 + Zeit.minute() * 60 + Zeit.second();
}

string Participant::ausgabe() const {
	return to_string(Zeit.hour()) + "h " + to_string(Zeit.minute()) + "m " + to_string(Zeit.second()) + "s ";
}
