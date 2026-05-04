#include "intvector.h"
#include <iostream>
using namespace std;

IntVector::IntVector(size_t length) {
	this->length = length;
	Array = new int[length];
}

IntVector::~IntVector() {
	delete[] Array;
}

size_t IntVector::size() const {
	return length;
}

int& IntVector::at(size_t idx) {
	if (idx >= 0 && idx < length) {
		return Array[idx];
	} else {
		throw runtime_error("Index out of range");
	}
}

void IntVector::out() const {
	for (size_t i = 0; i < length; i++) {
		cout << Array[i] << endl;
	}
}

IntVector::IntVector(const IntVector &other) {
	length = other.length;
	Array = new int[length];
	for (size_t i = 0; i < length; ++i) {
		Array[i] = other.Array[i];
	}
}

IntVector& IntVector::operator=(const IntVector &other) {
	if (this == &other) {
		return *this;
	}

	delete[] Array;

	length = other.length;
	Array = new int[length];
	for (size_t i = 0; i < length; ++i) {
		Array[i] = other.Array[i];
	}

	return *this;
}
