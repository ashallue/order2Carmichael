/* Author: Andrew Shallue, May 2020
part of summer project constructing order 2 Carmichael numbers
*/

// This file contains functions that solve the primality problem
// Input is an integer n, output is a boolean, True for prime
// Importantly, these are all proofs of primality

#include <vector>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

/************************functions with inputs as ZZ *****************/

// trial division of n up to a bound B
// returns bool.  False means provably composite, True means no factors less than B
bool is_prime_trialdivision(ZZ n, ZZ b);

/* ********************* functions with inputs as longs **************/

// primality using trial division
bool is_prime_trialdivision(long n);

// primality test via a base-b Fermat test.  False means 
// provably composite.  True means probably prime.
bool is_prime_fermat(long n, long b);

/* First version of Pocklington test.  This algorithm attempts to prove a number is prime.
If the number is prime, the running time is expected polynomial.  If the number is composite, 
it may be very slow, so make sure to apply a primality test first.
Input is n along with a factorization of n-1 given by a pair of vector<longs>
Output is a bool.  True means proven prime, False means failed to prove prime.
*/
bool pocklington1(long n, vector<long> prime_factors, vector<long> powers);

// Helper functions
// binary modular powering, computes a^e mod n
long mod_power1(long a, long e, long n);

long mod_power2(long a, long e, long n);

// gcd algorithm using standard recursive algorithm
long gcd(long a, long b);
