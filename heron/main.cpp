#include <iostream>
#include "pbma.h"
using namespace std;


int main(int argc, const char* argv[]) {
    
	args_t args(argc, argv);

	double x = args.double_pos(0, 10.0);
	double eps = args.double_pos(1, 1e-6);


    if (argc == 2) {
        x = atof(argv[1]);
    }
    if (argc == 3) {
        eps = atof(argv[2]);
    }

	if (x < 0){
		cout << "Von einer negativen Zahl kann keine Wurzel gezogen werden!" << endl;
		return 1;
	}
    
    double a_i = (1.0 + x) / 2.0;
    double a_next;

    
    while (true) {
        a_next = (a_i + (x / a_i)) / 2.0;

        
        if (a_i - a_next < eps) {
            break;
        }
        a_i = a_next;
    }

    
    cout << "heron(" << x << ", " << eps << ") = " << a_next << endl;

    return 0;
}