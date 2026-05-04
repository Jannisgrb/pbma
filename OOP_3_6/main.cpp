#include <iostream>
using namespace std;

struct Del {
	char arr[4] = "abc";

	Del(const char *a = 0, const char *b = 0, const char *c = 0) {
		if (a)
			arr[0] = *a;
		if (b)
			arr[1] = *b;
		if (c)
			arr[2] = *c;
	}
};

void out(const Del& del){
	cout << del.arr[0] << del.arr[1] << del.arr[2] << " ";
}

int main(int argc, const char *argv[]) {
	Del d1;
	Del d2("X");
	Del d3("X", "Y");
	Del d4("X", "Y", "Z");
	out(d1);
	out(d2);
	out(d3);
	out(d4);
	cout << endl;
}