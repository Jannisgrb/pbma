#include "header.h"
using namespace std;

int ggt1(int x, int y){

	if (y == x){
		return x;
	}
	if (x > y) {
	        return ggt1(x - y, y); 
	    } else {
	        return ggt1(x, y - x);
	    }

}

int ggt2(int x, int y){
	if (y == 0) {
        return x;
    }

    if (x == 0) {
        return y;
    }


    if (x > y) {
        return ggt2(x % y, y);
    } else {
        return ggt2(x, y % x);
    }
}