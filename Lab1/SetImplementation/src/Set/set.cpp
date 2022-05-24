#include "tuple.h"
#include "set.h"
#include "invariant.h"
#include <iostream>
#include <limits.h>   // needed for INT_MIN

// Set up an error set to be returned as necessary
const Set emptySet(0,(int*)0);
const Set errorSet(-1,(int*)0);

bool Set::isEmpty() const {

	if (_numElements == 0) {

		return true;

	}

	else

		return false;

}

bool Set::isError() const {

	if (_numElements < 0)

		return true;

	else

		return false;

}

int Set::cardinality() const {

	return _numElements;

}

Set Set::union_(const Set& s) const {

	if (s._numElements < 0 || _numElements < 0) {

		return errorSet;

	}

	else if (s._numElements == 0) {

		return *(this);

	}

	else if (_numElements == 0) {

		return s;

	}

	else {
	
		Tuple* temp_union = new Tuple[_numElements + s._numElements];	// Temporary tuple of size s1 +  s2

		for (int i = 0; i < _numElements; i++){	// Populate tuple with all the values of s1
	
			temp_union[i] = _pTuples[i];

		}


	
		int duplicates = 0;
		int sizebump = _numElements;
	
	for (int i = 0; i < s._numElements; i++) {

		duplicates = 0;

		for (int j = 0; j < _numElements; j++) {

			if (temp_union[j] == s._pTuples[i]) {

				duplicates = 1;
				
			}

		}

		if (duplicates == 0) {

			temp_union[sizebump] = s._pTuples[i];
			sizebump++;

		}

	}

		Tuple* UnionFinal = new Tuple[sizebump];

		for (int i  = 0; i < sizebump; i++){

			UnionFinal[i] = temp_union[i];

		}

		return Set(sizebump, UnionFinal);	

	}

}

Set Set::intersection(const Set& s) const {

	int sizebump = 0;
	Tuple* temp_intersect = new Tuple[_numElements];	// Temporary tuple of size s1


	if (s._numElements < 0 || _numElements < 0) {

		return errorSet;

	}

	else if (s._numElements == 0) {

		return emptySet;

	}

	else if (_numElements == 0) {

		return emptySet;

	}

	else {
	
		int duplicates = 0;

		for (int i = 0; i < s._numElements; i++) {

			duplicates = 0;

			for (int j = 0; j < _numElements; j++) {

					if (_pTuples[j] == s._pTuples[i]) {

						duplicates = 1;
				
					}

			}

			if (duplicates == 1) {

				temp_intersect[sizebump] = s._pTuples[i];
				sizebump++;

			}

		}

	}

	Tuple* UnionFinal = new Tuple[sizebump];

	for (int i  = 0; i < sizebump; i++){

		UnionFinal[i] = temp_intersect[i];

	}

	return Set(sizebump, UnionFinal);	

}

Set Set::difference(const Set& s) const {

	Tuple* temp_union = new Tuple[_numElements + s._numElements];	// Temporary tuple of size s1 +  s2

	if (s._numElements < 0 || _numElements < 0) {

		return errorSet;

	}

	else if (s._numElements == 0) {

		return *(this);

	}

	else if (_numElements == 0) {

		return s;

	}

	else {
	
		Tuple* temp_union = new Tuple[_numElements];	// Temporary tuple of size s1 +  s2

		int duplicates = 0;
		int sizebump = 0;
	
	for (int i = 0; i < _numElements; i++) {

		duplicates = 0;

		for (int j = 0; j < s._numElements; j++) {

			if (_pTuples[i] == s._pTuples[j]) {

				duplicates = 1;
				
			}

		}

		if (duplicates == 0) {

			temp_union[sizebump] = _pTuples[i];
			sizebump++;

		}

	}

		Tuple* UnionFinal = new Tuple[sizebump];

		for (int i  = 0; i < sizebump; i++){

			UnionFinal[i] = temp_union[i];

		}

		return Set(sizebump, UnionFinal);	

	}

}

Set Set::select(predicate* p) const {

	if (_numElements < 0) {

		return errorSet;

	}

	int sizebump = 0;

	Tuple* temp_select = new Tuple[_numElements];

	for (int i = 0; i < _numElements; i++) {

		if ((*p)(_pTuples[i])) {

			temp_select[sizebump] = _pTuples[i];

			sizebump++;

		}

	}

	Tuple* UnionFinal = new Tuple[sizebump];

	for (int i  = 0; i < sizebump; i++){

		UnionFinal[i] = temp_select[i];

	}

	return Set(sizebump, UnionFinal);	
	
}

Set Set::project(const int numItems, const int items[]) const {

	if (isEmpty() || _numElements == 0) {
		return emptySet;
	}

	if (isError() || _numElements < 0) {
		return errorSet;
	}

	Tuple temp[_numElements];

	for (int i = 0; i < _numElements; i++) {

		int d[numItems];

		for (int j = 0; j < numItems; j++) {

			d[j] = _pTuples[i](items[j]);

		}

		temp[i] = Tuple(numItems, d);
	}

	return Set(_numElements, temp);

}

Set Set::cartesian(const Set& s) const {

	if (s._numElements < 0 || _numElements < 0) {

		return errorSet;

	}

	else if (s._numElements == 0) {

		return emptySet;

	}

	else if (_numElements == 0) {

		return emptySet;

	}

	Tuple* temp_car= new Tuple[_numElements * s._numElements];

	int sizebump = 0;

	for (int i = 0; i < this->_numElements; i++) {

		for (int j = 0; j < s._numElements; j++) {

			temp_car[sizebump] = this->_pTuples[i].operator+(s._pTuples[j]);

			sizebump++;

		}

	}

	Tuple* UnionFinal = new Tuple[sizebump];

	for (int i  = 0; i < sizebump; i++){

		UnionFinal[i] = temp_car[i];

	}

	return Set(sizebump, UnionFinal);	

}

Set Set::operator() (const int item) const {
	return emptySet;
}


void Set::operator=(const Set& s) {

	_numElements = s._numElements;
	_pTuples = new Tuple[s._numElements + 1];
	_tupleArraySize = s._tupleArraySize;

	for (int i = 0; i < s._numElements; i++) {

		_pTuples[i] = s._pTuples[i];

	}

}

Set::Set() {

	_numElements = 0;
	_pTuples = new Tuple[10];
	_tupleArraySize = 10;

}

Set::Set(const Set& s) {

	_numElements = s._numElements;
	_tupleArraySize = s._numElements;

	for (int i = 0; i < s._numElements; i++) {

		_pTuples[i] = s._pTuples[i];

	}
	
}

Set::Set(const int numElements, const int data[]) {

	_numElements = numElements;

	if (_numElements == 0) {

		_pTuples = NULL;
		_tupleArraySize = 0;

	}

	else if (_numElements < 0) {

		_pTuples = NULL;
		_tupleArraySize = -1;

	}

	else {

		_pTuples = new Tuple[_numElements];

		int sizebump = 0;

		for (int i = 0; i < _numElements; i++) {

			int found = 0;

			Tuple tuple = Tuple(data[i]);

			for (int j = 0; j < sizebump; j++) {

				if (tuple == _pTuples[j]) {

					found = 1;

				}

			}

			if (found == 0) {

				_pTuples[sizebump] = tuple;

				sizebump++;

			}

		}

		_numElements = sizebump;

	}

}

Set::Set(const int numElements, const Tuple tuples[]) {

	_numElements = numElements;

	if (_numElements == 0) {

		_pTuples = NULL;
		_tupleArraySize = 0;

	}

	else if (_numElements < 0) {

		_pTuples = NULL;
		_tupleArraySize = -1;

	}

	else {

		_pTuples = new Tuple[_numElements];

		int counter = 0;

		for (int i = 0; i < _numElements; i++) {

			int found = 0;

			for (int j = 0; j < counter; j++) {

				if (tuples[i] == _pTuples[j]) {

					found = 1;

				}
			}

			if (found == 0) {

				_pTuples[counter] = tuples[i];

				counter++;

			}

		}

		_numElements = counter;

	}

}

Set::~Set() {

	_numElements = 0;
	_tupleArraySize = 0;

}

std::ostream& operator<<(std::ostream& os, const Set& s) {

	if (s._numElements == 0) {

		os << "{}";

		return os;

	}

	else if (s._numElements == -1) {

		os << "{Error}";

		return os;

	}

	else if (s._numElements > 0) {

		os << "{";

		for (int i = 0; i < s._numElements; i++) {

			os << s._pTuples[i];

			if (i + 1 != s._numElements) {

				os << ",";

			}

		}

		os << "}";

		return os;

	}

	else {

		std::cerr << "Error";

		exit(-1);

	}

}