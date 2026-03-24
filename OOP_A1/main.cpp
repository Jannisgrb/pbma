#include <iostream>
#include <iomanip>
#include <limits>
#include <sys/types.h>
using namespace std;

int main() {
cout << setw(20) << "int"
	<< " " << sizeof(int) << ": ";
cout << setw(20) << numeric_limits<int>::min() << "...";
cout << setw(20) << numeric_limits<int>::max() << endl;


cout << setw(20) << "unsigned int"
	<< " " << sizeof(unsigned) << ": ";
cout << setw(20) << numeric_limits<unsigned>::min() << "...";
cout << setw(20) << numeric_limits<unsigned>::max() << endl;


cout << setw(20) << "long"
	<< " " << sizeof(long) << ": ";
cout << setw(20) << numeric_limits<long>::min() << "...";
cout << setw(20) << numeric_limits<long>::max() << endl;


cout << setw(20) << "unsigned long"
	<< " " << sizeof(ulong) << ": ";
cout << setw(20) << numeric_limits<ulong>::min() << "...";
cout << setw(20) << numeric_limits<ulong>::max() << endl;


cout << setw(20) << "float"
	<< " " << sizeof(float) << ": ";
cout << setw(20) << numeric_limits<float>::min() << "...";
cout << setw(20) << numeric_limits<float>::max() << endl;


cout << setw(20) << "double"
	<< " " << sizeof(double) << ": ";
cout << setw(20) << numeric_limits<double>::min() << "...";
cout << setw(20) << numeric_limits<double>::max() << endl;
}