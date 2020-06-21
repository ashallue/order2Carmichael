#pragma once

#ifndef factorization
#define factorization

/*
Andrew Shallue, summer 2020, part of the project to construct Order 2 Carmichael numbers
Alex Seehuus created a Factorization class based on long data type.  Here I'm converting it to ZZs
*/

#include "NTL/ZZ.h"
#include <vector>

using namespace std;
using namespace NTL;



class Factorization {
	// private data members are the unique prime factors and the powers of those prime factors
	// represents an integer n of the form p1^e1 * p2^e2 * p3^e3 ... * pk^ek
private:
	vector<ZZ> primes;
	vector<ZZ> powers;

public:
	// default constructor makes both vectors empty
	Factorization();
	// this constructor takes a pair of vectors as input
	Factorization(vector<ZZ> input_primes, vector<ZZ> input_powers);

	// getter functions
	vector<ZZ> getPrimes();
	vector<ZZ> getPowers();

	// return the number n being represented
	ZZ factorProduct();

	// check that primes and powers are the same length
	bool validFactorization();
};

#endif 
