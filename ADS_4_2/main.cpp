#include <iostream>
#include <vector>
#include <algorithm>
#include "pbma.h"
using namespace std;

void countsort(vector<int> &a);

int main() {
	check_sort(countsort, true, true);
}

void countsort(vector<int> &a) {
	int min = *min_element(a.begin(), a.end()), max = *max_element(a.begin(), a.end());
	int Wertebereich = max - min + 1;
	vector<int> Counter(Wertebereich);

	for (size_t i = 0; i < a.size(); i++) {
		Counter[-min + a[i]] += 1;
	}

	int out_index = 0;
	for(size_t i = 0; i < Counter.size(); i++){
		while(Counter[i] > 0){
			a[out_index] = i + min;
			out_index++;
			Counter[i]--;
		}
	}
}
