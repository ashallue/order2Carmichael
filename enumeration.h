/*Enumerating function
Alex Seehuus, 2020*/
#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include "factorization.h"
#include "primality.h"

using namespace std;
using namespace NTL;


//a function used to enumerate all divisors given the prime factors
vector<ZZ> enumerate(Factorization factors, ZZ bound);

//print function
void print(vector<ZZ> to_print);

//function to remove leadind and trailing zeroes from a vector
void Rzeros(vector<ZZ>& vect);

//function to get divisors upto a bound
void Rbound(vector<ZZ>& vect, ZZ bound);

//given a list of divisors, discard the ones that don't satisfy the following conditions:
//divisor d must be of the form p^2-1 for p prime
//p must not divide L
//written by Andrew Shallue
vector<ZZ> order2_primes(vector<ZZ>& divisors, Factorization L);

/** Written by Bobby Koirala
 * Returns true if `n2` is a perfect square, and stores the square root in `n`.
 * If `n2` is not a prefect square, the value of `n` is not changed.
 *
 * @param n  referce to a NTL::ZZ where the square root is stored if `n2` is a
 *           perfect square
 * @param n2 the number to check if it is a perfect square
 */
bool is_perfect_square(NTL::ZZ& n, const NTL::ZZ& n2);

