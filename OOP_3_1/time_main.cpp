#include <iostream>
#include "Time.h"
using namespace std;

int main() {
	Time t1(1, 30, 45);
	Time t2(0, 15, 20);

	cout << "Startzeit t1: " << t1.ausgabe() << endl;

	t1.add(t2);
	cout << "Nach add(t2): " << t1.ausgabe() << endl;

	t1.add_minutes(10);
	cout << "Nach add_minutes(10): " << t1.ausgabe() << endl;

	t1.add_hours(-5);

	Time t3(0, 0, 50);
	Time t4(0, 1, 0);
	cout << "Sekunden von t4: " << t4.justseconds() << endl;
	cout << "Diff (t3 - t4): " << t3.diff(t4) << " Sekunden" << endl;

	return 0;
}
