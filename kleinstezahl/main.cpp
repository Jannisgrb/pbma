#include <iostream>
#include "pbma.h"
using namespace std;


int main(int argc, const char* argv[]){

	args_t args(argc, argv);

	string filename = args.pos(0, "zahlen.dat");
	vector<int> zahlen = read_ints(filename);

	int min = zahlen[0];

	for(int i = 1; i < zahlen.size(); i++){
		if (zahlen[i] < min){
			min = zahlen[i];
	}
}

cout << "Die kleinste Zahl in der Datei ist " << min << endl;


}