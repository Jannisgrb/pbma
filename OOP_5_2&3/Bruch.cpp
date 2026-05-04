#include "Bruch.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Bruch::Bruch(int Zaehler, int Nenner) {
	this->Zaehler = Zaehler;
	this->Nenner = Nenner;
	normalisiere();
}

int Bruch::ggt(int a, int b) {
	a = (a < 0) ? -a : a;
	b = (b < 0) ? -b : b;
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void Bruch::normalisiere() {
	if (Nenner == 0) {
		throw runtime_error("Nenner darf nicht 0 sein!");
	}
	if (Nenner < 0) {
		Zaehler = -Zaehler;
		Nenner = -Nenner;
	}

	int ggt_value = ggt(Zaehler, Nenner);
	Zaehler /= ggt_value;
	Nenner /= ggt_value;
}

int Bruch::zaehler() const { return Zaehler; }

int Bruch::nenner() const { return Nenner; }

bool operator==(const Bruch &links, const Bruch& rechts){
	if (links.zaehler() == rechts.zaehler() && links.nenner() == rechts.nenner()) {
		return true;
	} else {
		return false;
	}
}

bool operator!=(const Bruch &links, const Bruch& rechts){
	if (links.zaehler() == rechts.zaehler() && links.nenner() == rechts.nenner()) {
		return false;
	} else {
		return true;
	}
}

Bruch& Bruch::operator*=(const Bruch &other){
	this->Zaehler *= other.Zaehler;
	this->Nenner *= other.Nenner;
	normalisiere();
	return *this;
}

Bruch operator*(Bruch links, const Bruch& rechts) {
    links *= rechts;
    return links;
}