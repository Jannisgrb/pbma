#include <iostream>
#include <vector>
#include "Time.h"
#include "Participant.h"
#include "pbma.h"
using namespace std;

int main(int argc, const char *argv[]) {
	//int n = argc-1;
	vector<string> Teilnehmer_Namen(argc-1);
	for (int i = 0; i < argc-1; i++) {
		Teilnehmer_Namen[i] = argv[i + 1];
	}

	vector<Participant> teilnehmer(argc-1);
	vector<int> Times = create_randints(argc-1, 0, 1000);

	for (int i = 0; i < argc-1; i++) {
		//Participant a {Teilnehmer_Namen[i]};
		// a.give_time();
		//teilnehmer.push_back(a);
		teilnehmer[i].give_name(Teilnehmer_Namen[i]);
		teilnehmer[i].give_time(Time(0, 0, Times[i]));
	}

	Participant winner = teilnehmer[0];
	for (size_t i = 0; i < teilnehmer.size(); i++){
		if (teilnehmer[i].justseconds() < winner.justseconds()){
			winner = teilnehmer[i];
		}
	}

	cout << "Es haben " << teilnehmer.size() << " Teilnehmer am Rennen teilgenommen" << endl;
	cout << "Der Gewinner ist " << winner.return_name() << " mit einer Zeit von " << winner.ausgabe() << endl;
}
