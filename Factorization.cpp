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

// check if a given prime is in the factorization
// if it is, return the corresponding index.  If not, return -1
long Factorization::containsPrime(ZZ p) {
	// loop over the primes list
	for (long i = 0; i < primes.size(); i++) {
		if (primes.at(i) == p) {
			return i;
		}
	}
	// if we haven't found it in the loop, return 0
	return -1;
}

// add a new prime to the factorization.  
// if new, added to back of primes vector with corresponding power 1
// if already exists in factorization, add one to power
void Factorization::addPrime(ZZ p) {
	// first check that p really is (probably) prime
	if (!ProbPrime(p)) {
		cout << "Error in addPrime, " << p << " is not prime\n";
	}else{
		// next check whether p is already in the Factorization
		long p_index = containsPrime(p);
		if (p_index >= 0) {
			// add one to corresponding power
			powers.at(p_index)++;
		}
		else {
			// otherwise push it on the back
			primes.push_back(p);
			powers.push_back(to_ZZ(1));
		}
	}
}

// print primes and powers to stdout
void Factorization::print() {
	// print prime and its corresponding power in pairs
	cout << "Factorization: ";
	for (long i = 0; i < primes.size(); i++) {
		cout << "( " << primes.at(i) << ", " << powers.at(i) << " )  ";
	}
	cout << "\n";
}