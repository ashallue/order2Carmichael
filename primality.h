/* Author: Andrew Shallue, May 2020
part of summer project constructing order 2 Carmichael numbers
*/

// This file contains functions that solve the primality problem
// Input is an integer n, output is a boolean, True for prime
// Importantly, these are all proofs of primality

using namespace std;

// primality using trial division
bool is_prime_trialdivision(long n);


// Helper functions
// binary modular powering, computes a^e mod n
long mod_power1(long a, long e, long n);

long mod_power2(long a, long e, long n);
