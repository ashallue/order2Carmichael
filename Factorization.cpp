/*
Andrew Shallue, summer 2020, part of the project to construct Order 2 Carmichael numbers
Alex Seehuus created a Factorization class based on long data type.  Here I'm converting it to ZZs
*/

#include "Factorization.h"

// default constructor makes both vectors empty
Factorization::Factorization() {
	primes = vector<ZZ>();
	powers = vector<ZZ>();
}

// this constructor takes a pair of vectors as input
Factorization::Factorization(vector<ZZ> input_primes, vector<ZZ> input_powers) {
	primes = input_primes;
	powers = input_powers;
}

// getter functions
vector<ZZ> Factorization::getPrimes() {
	return primes;
}
vector<ZZ> Factorization::getPowers() {
	return powers;
}

// return the number n being represented
ZZ Factorization::factorProduct() {
	ZZ n = to_ZZ(1);

	// loop over p in the primes list
	for (long i = 0; i < primes.size(); i++) {
		// multiple by p a number of times equal to the corresponding power
		for (long j = 0; j < powers.at(i); j++) {
			n = n * primes.at(i);
		}
	}

	return n;
}

// check that primes and powers are the same length
bool Factorization::validFactorization() {
	return primes.size() == powers.size();
}