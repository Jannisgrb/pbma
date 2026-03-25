#include <iostream>
#include "header.h"
#include "pbma.h"
#include <vector>
using namespace std;

int main(int argc, const char* argv[]){

	args_t args(argc, argv);
	string fname = args.pos(0, "ggts.dat"); // (position, default-Wert)
	Timer timer;
	vector<int> zahlen = read_ints(fname);
	vector<int> ggts1;
	vector<int> ggts2;
	int summe_ggt1 = 0, summe_ggt2 = 0;
	cout << "Einlesen dauerte " << timer.human_measure() << endl;

	Timer t_ggt1;
	for(int i = 0; i < zahlen.size(); i = i + 2){
		ggts1.push_back(ggt1(zahlen[i], zahlen[i+1]));
	}
	cout << "Berechnung mit ggt1 dauerte " << t_ggt1.human_measure() << endl;


	Timer t_ggt2;
	for(int i = 0; i < zahlen.size(); i = i + 2){
		ggts2.push_back(ggt2(zahlen[i], zahlen[i+1]));
	}
	cout << "Berechnung mit ggt2 dauerte " << t_ggt2.human_measure() << endl;


	for(int i = 0; i < ggts1.size(); i++){
		summe_ggt1 = summe_ggt1 + ggts1[i];
	}


	for(int i = 0; i < ggts2.size(); i++){
		summe_ggt2 = summe_ggt2 + ggts2[i];
	}

	cout << "Die Summe aller ggt1 lautet " << summe_ggt1 << endl;
	cout << "Die Summe aller ggt2 lautet " << summe_ggt2 << endl;

return 0;
}
