#include <iostream>
#include <vector>
#include "pbma.h"
using namespace std;

void SelectionSort(vector<int>& a);
void InsertionSort(vector<int>& a);
void MergeSort(vector<int>& a);
inline void mycopy(vector<int>& dest, vector<int>& src, size_t from, size_t to);
void mergen(vector<int>& a, vector<int>& b, size_t li, size_t end_li, size_t re, size_t end_re);
void merge_sort(vector<int>& a, vector<int>& b, size_t li, size_t re);


int main(){
	vector<int> zahlen = create_randints(10, 0, 100);

//	SelectionSort(zahlen);
//	InsertionSort(zahlen);
//	MergeSort(zahlen);
//
//	int first_error;
//	if(is_sorted(zahlen, first_error)){
//		cout << "Sortiert!" << endl;
//	}else{
//		cout << "Fehler an Position: " << first_error << endl;
//	}

	check_sort(SelectionSort(), true);
}



void SelectionSort(vector<int>& a){
	size_t asize = a.size();
	for (size_t i = 0; i < asize - 1; i +=1){
		size_t min = i;
		for (size_t j = i + 1; j < asize; j += 1){
			if(a[min] > a[j]){
				min = j;
			}
		}
		if(min != i){
			swap(a, min, i);
		}
	}
}

void InsertionSort(vector<int>& a){
	size_t asize = a.size();
	for (size_t i = 1; i < asize; i += 1) {
		size_t j = i;
		while ((j > 0) && (a[j - 1] > a[j])) {
			swap(a, j - 1, j);
			j -= 1;
		}
	}
}

void MergeSort(vector<int>& a){
	vector<int> b(a.size());
	merge_sort(a, b, 0, a.size() - 1);
}

inline void mycopy(vector<int>& dest, vector<int>& src, size_t from, size_t to){
	for (size_t idx = from; idx < to; idx += 1) {
		dest[idx] = src[idx];
	}
}

void mergen(vector<int>& a, vector<int>& b, size_t li, size_t end_li, size_t re, size_t end_re) {
	size_t start = li, end = end_re;
	size_t i = li;
	while (li <= end_li && re <= end_re) {
		if (a[li] <= a[re]) { // stabiles Sortieren
			swap(b, i++, a, li++); // b[i++] = a[li++];
		} else {
			swap(b, i++, a, re++); // b[i++] = a[re++];
		}
	}
	while (li <= end_li) {
		swap(b, i++, a, li++); // b[i++] = a[li++];
	}
	while (re <= end_re) {
		swap(b, i++, a, re++); // b[i++] = a[re++];
	}
	mycopy(a, b, start, end + 1); // zurück in a kopieren
}

void merge_sort(vector<int>& a, vector<int>& b, size_t li, size_t re) {
	if (li == re) { // Einelementig ist sortiert
		return;
	}
	size_t mi = li + (re - li) / 2;
	merge_sort(a, b, li, mi);
	merge_sort(a, b, mi + 1, re);
	mergen(a, b, li, mi, mi + 1, re);
}
