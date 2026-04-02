#include "intvec.h"
#include <iostream>
#include <vector>
using namespace std;

void ivec_init(intvec* ivec, size_t cap){
	ivec->capacity = cap;
	ivec->size = 0;
	ivec->arr = new int[cap];
}

void ivec_clear(intvec* ivec){
	delete[] ivec->arr;
	ivec->capacity = 0;
	ivec->size = 0;
	ivec->arr = nullptr;
}

void ivec_pushback(intvec* ivec, int ele){
	if (ivec->size >= ivec->capacity){
		size_t new_cap = (ivec->capacity == 0) ? 1:ivec->capacity*2;
		int* new_arr = new int[new_cap];

		for(size_t i = 0; i < ivec->size; ++i) {
				new_arr[i] = ivec->arr[i];
		}

		delete[] ivec->arr;
		ivec->arr = new_arr;
		ivec->capacity = new_cap;
	}

	ivec->arr[ivec->size] = ele;
	ivec->size++;
}

int& ivec_at(intvec* ivec, size_t idx){
	if(ivec->size < idx){
		cerr << "Dieser wert existiert nicht!" << endl;
	}
	return ivec->arr[idx];
}

int ivec_sum(intvec* ivec){
	int sum = 0;
	for(size_t i = 0; i < ivec->size; i++){
		sum += ivec->arr[i];
	}
	return sum;
}
