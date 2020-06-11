/* Author: Andrew Shallue, May 2020
part of the constructing order 2 Carmichael numbers project
*/

#include "primality.h"
#include <cmath>
#include <iostream>

// This file contains functions that solve the primality problem
// Input is an integer n, output is a boolean, True for prime
// Importantly, these are all proofs of primality

// The first method is trial division: we check for divisors up to sqrt(n)
bool is_prime_trialdivision(long n){
  // if n < 1, print an error, return false
  // if n = 1, return false, since 1 is not prime
  if (n < 1){
    cout << "Error in is_prime_trialdivision, input is < 1\n";
    return false;
  }
  if(n == 1){
    return false;
  }

  // initially assume the number is prime
  bool output = true;

  // If n has a divisor, it will have one less than sqrt(n).
  // Check all divisors up to that bound using a loop
  for(long i = 2; i <= floor(sqrt(n)); i++){
    if(n % i == 0){
      output = false;
      break;
    }
  }
  return output;
}

// primality test via a base-b Fermat test.  False means 
// provably composite.  True means probably prime.
bool is_prime_fermat(long n, long b){
  // first compute b^(n-1) mod n using mod_power1
  long power = mod_power1(b, n-1, n);

  // now return boolean value of whether that power equals 1
  return power == 1;
}

/* This next method is more efficient, but depends on having 
the factorization of p-1 in hand.  Note that factoring is a hard problem in general, but with pseudoprime construction we often have the factorization given to us since we are checking divisors
*/

/* This is a fast modular powering algorithm, also called binary exponentiation.  
Reference: https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
Iterative, runs in time $O(log e) word operations
Computes a^e mod n
*/

long mod_power1(long a, long e, long n){
  // start with our output set to 1, will grow as e shrinks
  long result = 1;

  // continue until e is 0.  Will tackle it one bit at a time
  while(e > 0){
    // if e is odd, multiply by a and reduce modulo n
    if(e % 2 == 1){
      e = e - 1;
      result = (result * a) % n;
    }
    // at this point e is even, so divide e by 2, square base
    e = e >> 1; // bit shift, equivalent to divide by 2
    a = (a * a) % n;
  }

  return result;
}

long mod_power2(long a, long e, long n){
  /* Step 1, find the bit repr of e, store bits in an array */

  // create an array which contains the bit repr of e
  // its length is floor(log_2(e)) + 1
  long bitlength = 1 + floor(log(e)/log(2));
  long* bits = new long[bitlength];

  long power = e;

  // now fill in the bit vector, starting with least significant
  for(long i = 0; i < bitlength; i++){
    if(power % 2 == 1){
      bits[i] = 1;
      // now subtract 1 and divide by 2 to set up next bit
      power = (power - 1) >> 1;
    }else{
      bits[i] = 0;
      // in the even case, just divide by 2
      power = power >> 1;
    }
  }
  /* Step 2, given bits of e, do binary exponentiation */

  // initialize result to 1
  long result = 1;

  // Now start with most significant bit
  // if 1, multiply and square.  If 0, just square
  for(long i = bitlength-1; i >= 0; i--){
    if(bits[i] == 1){
      result = (result * a) % n;
    }
    // except for the last bit, square
    if(i > 0){
      result = (result * result) % n;
    }
  }

  return result;
}
