#include <iostream>
#include <ostream>
#include <vector>
#include "pbma.h"
using namespace std;

int main(int argc, const char* argv[]){
	args_t args(argc, argv);
	string input_fname = args.pos(0, "lena.pgm");
	string output_fname = args.pos(1, "out.pgm");
	double Schwellenwert = args.double_pos(2, 50);

	vector<int> Ursprungswerte = read_pgm(input_fname);

	cout << "Breite: " << Ursprungswerte[0] << endl;
	cout << "Höhe: " << Ursprungswerte[1] << endl; 
	cout << "Maximale Helligkeit: " << Ursprungswerte[2] << endl; 

	for(unsigned int i = 3; i < Ursprungswerte.size(); i++){
		if (Ursprungswerte[i] < 255 * (Schwellenwert/100)){
			Ursprungswerte[i] = 0;
		}

		if (Ursprungswerte[i] >= 255 * (Schwellenwert/100)){
			Ursprungswerte[i] = 255;
		}
	}

	save_pgm(output_fname, Ursprungswerte);
}