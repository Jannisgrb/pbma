#include <iostream>
#include <utility>
using namespace std;

struct KVT{
	int val;
	KVT(int) : val(2){}
	KVT(float) : val(17){}
	KVT(double) : val(42){}
	KVT(char) : val(66){}
	KVT(short) : val(2){}
};

void out(KVT kvt) {
	cout << kvt.val << " ";
}

int main(int argc, const char* argv[]){
	out(1); out((short)1); out (1.9f); out(3.1415); out('x');
	cout << endl; 
}
