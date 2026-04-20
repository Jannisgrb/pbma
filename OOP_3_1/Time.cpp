#include <iostream>
#include "Time.h"
using namespace std;

Time::Time(long h, long m, long s){
	this->h = h;
	this->m = m;
	this->s = s;

	correct();
}

void Time::correct() {
	m += s / 60;
	s %= 60;
	h += m / 60;
	m %= 60;

	if (h < 0 || (h == 0 && m < 0) || (h == 0 && m == 0 && s < 0)) {
		h = m = s = 0;
		cout << "Fehlerhafte Eingabe --> Zeit auf 0 gesetzt!" << endl;
	}
}

void Time::add(const Time& other) {
	h += other.h;
	m += other.m;
	s += other.s;

	correct();
}

void Time::add_hours(long hours) {
	h += hours;
	if (hours < 0) {
		h = m = s = 0;
		cout << "Fehlerhafte Eingabe --> Zeit auf 0 gesetzt!" << endl;
	}
}

void Time::add_minutes(long minutes) {
	m += minutes;
	if (minutes < 0) {
		h = m = s = 0;
		cout << "Fehlerhafte Eingabe --> Zeit auf 0 gesetzt!" << endl;
	}
	correct();
}

void Time::add_seconds(long seconds) {
	s += seconds;
	if (seconds < 0) {
		h = m = s = 0;
		cout << "Fehlerhafte Eingabe --> Zeit auf 0 gesetzt!" << endl;
	}
	correct();
}

long Time::justseconds() const {
	return h * 3600 + m * 60 + s;
}

long Time::diff(const Time& other){
	return justseconds() - other.justseconds();
}

string Time::ausgabe() const{
	return to_string(h) + "h " + to_string(m) + "m " + to_string(s) + "s ";
}
