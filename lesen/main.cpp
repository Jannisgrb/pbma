#include <cstddef>
#include <iostream>
#include "pbma.h"
#include <fstream>
using namespace std;

int main(int argc, const char *argv[]){
	args_t args (argc, argv);
	string dat_name = args.pos(0, "zahlen.dat");
	bool verbose = args.flag("-v");
	
	vector<int> zahlen;
	ifstream dat(dat_name);
	
	int n;
	dat >> n;

	zahlen.reserve(n);
	
	int wert;
	while(dat >> wert){
		zahlen.push_back(wert);
	}
	
	if(zahlen.size() != (size_t)n) {
	cerr << "Fehler: Anzahl der Zahlen stimmt nicht mit angegebener Anzahl überein!!!" << endl;	
	return -1;
	}
	
	int from = args.int_pos(1, 0);
	int to = args.int_pos(2, (int)zahlen.size());

	if(from < 0 || from > to || from > (int)zahlen.size()){
		cerr << "Argumente nicht sinnvoll!!!" << endl;
		return -1;
	}
	if(to > (int)zahlen.size()){
		to = (int)zahlen.size();
	}

	if(verbose){
		for(int i = 0; i < (int)zahlen.size(); i++){
			cout << i << ": " << zahlen[i] << endl;
		}
	}

	int min_all = zahlen[0], max_all = zahlen[0];
	double sum_all = 0;
	for(size_t i = 0; i < zahlen.size(); i++){
		if(zahlen[i] < min_all)
			min_all = zahlen[i];
		
		if(zahlen[i] > max_all)
			max_all = zahlen[i];

		sum_all += zahlen[i];
	}

	cout << "Anzahl: " << zahlen.size() << endl;
	cout << "Gesamt: \nMin: " << min_all << " Max: " << max_all << " Schnitt: " << sum_all/(int)zahlen.size() << endl;

	if (args.len_pos() > 1) {   
            int min_sub = zahlen[from];
            int max_sub = zahlen[from];
            double sum_sub = 0;
            int count_sub = 0;

            for (int i = from; i < to; i++) {
                if (zahlen[i] < min_sub) min_sub = zahlen[i];
                if (zahlen[i] > max_sub) max_sub = zahlen[i];
                sum_sub += zahlen[i];
                count_sub++;
            }

            if (count_sub > 0) {
                cout << "Bereich [" << from << "," << to << ") - Min: " << min_sub 
                     << " Max: " << max_sub << " Schnitt: " 
                     << fixed << setprecision(2) << (sum_sub / count_sub) << endl;
            }
        }
 }