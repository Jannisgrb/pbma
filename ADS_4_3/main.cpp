#include <iostream>
#include <vector>
#include "pbma.h"
using namespace std;

void HeapSort(vector<int> &list);
void bubble_up(vector<int> &baum);
void bubble_down(vector<int> &baum);

int main() {
	check_sort(HeapSort, true);
}

void HeapSort(vector<int> &list) {
	vector<int> baum(list.size() + 1);
	baum[1] = list[0];
	for (size_t i = 2; i < list.size(); i++) {
		baum[i] = list[i - 1];
		bubble_up(baum);
	}
}

void bubble_up(vector<int> &baum) { //Muss von unten nach oben abfragen (und nicht wie gerade von oben nach unten)
	for (size_t i = 1; i < baum.size(); i++) {
		if(baum[i] > baum[i*2]){
			swap(baum[i], baum[i*2]);
		}
		else if(baum[i] > baum[i*2+1]){
			swap(baum[i], baum[i*2+1]);
		}
	}
}

void bubble_down(vector<int> &baum) {

}
