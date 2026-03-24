#include <iostream>
#include <ostream>
using namespace std;

int ggt1(int x, int y){
	if (x < y){
	y = y - x;

}

	if (y < x){
	x = x - y;

}

	if (y == x){
	return x;
}

return ggt1(x, y);
}

int ggt2(int x, int y){
	
	if (x < y){
	y = y % x;
}

	if (y < x){
	x = x % y;
}

	if (x == 0){
	return y;
}

	if (y == 0){
	return x;
}

return ggt2(x, y);
}


int main(){
int x = 45;
int y = 10;
int ggt = ggt1(45, 10);
int ggt_2 = ggt2(45, 100);

cout << "Größter gemeinsamer Teiler von " << x << " & " << y << ": " << ggt << endl;
cout << "Größter gemeinsamer Teiler von " << x << " & " << y << ": " << ggt_2 << endl;

return 0;
}