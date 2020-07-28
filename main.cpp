/* Author: Andrew Shallue, May 2020
Constructing order 2 Carmichael numbers
*/

#include <iostream>
#include <cmath>
#include "primality.h"
#include <vector>
#include "Factorization.h"
#include "enumeration.h"

using namespace std;
using namespace NTL;

int main() {
  std::cout << "Hello World!\n";
  
  /*
  // Testing Factorization on 2 * 3 * 5
  Factorization f; vector<ZZ> p; vector<ZZ> pow;
  p.push_back(to_ZZ(2));  p.push_back(to_ZZ(3));  p.push_back(to_ZZ(5));
  pow.push_back(to_ZZ(1)); pow.push_back(to_ZZ(1)); pow.push_back(to_ZZ(1));
  f = Factorization(p, pow);
  f.print();
  */
  /*
  // Testing Factorization class on 2^5 * 11 * 41^2 * 101 = 59762912
  Factorization f; vector<ZZ> p; vector<ZZ> pow;
  p.push_back(to_ZZ(2)); p.push_back(to_ZZ(11)); p.push_back(to_ZZ(41)); p.push_back(to_ZZ(101));
  pow.push_back(to_ZZ(5)); pow.push_back(to_ZZ(1)); pow.push_back(to_ZZ(2)); pow.push_back(to_ZZ(1));
  f = Factorization(p, pow);
  f.print();
  */

  //vector<ZZ> lst = enumerate(f, to_ZZ(1000000000));
  //print(lst);

  // Testing Factorization on 2^5 * 3^2 * 5 * 7 * 11 * 13
  Factorization L; vector<ZZ> p2; vector<ZZ> pow2;
  p2.push_back(to_ZZ(2)); p2.push_back(to_ZZ(3)); p2.push_back(to_ZZ(5)); 
  p2.push_back(to_ZZ(7)); p2.push_back(to_ZZ(11)); p2.push_back(to_ZZ(13));
  pow2.push_back(to_ZZ(5)); pow2.push_back(to_ZZ(2)); pow2.push_back(to_ZZ(1));
  pow2.push_back(to_ZZ(1)); pow2.push_back(to_ZZ(1)); pow2.push_back(to_ZZ(1));

  L = Factorization(p2, pow2);
  L.print();
  vector<ZZ> lst = enumerate(L, to_ZZ(1000));
  cout << "All divisors of L less than the bound: \n";
  print(lst);
  cout << "\n";

  vector<ZZ> primes = order2_primes(lst, L);
  cout << "primes p such that p^2-1 | L \n";
  print(primes);

  /* Testing of previous code from primality and Factorization

  cout << is_prime_trialdivision(to_ZZ(14039), to_ZZ(23)) << "\n";
  cout << is_prime_trialdivision(to_ZZ(14039), to_ZZ(120)) << "\n";

  cout << f.factorProduct() << "\n";
  cout << f.validFactorization() << "\n";
  f.print();
  f.addPrime(to_ZZ(103));
  f.print();
  f.addPrime(to_ZZ(2));
  f.print();
  
  cout << "\n";
  cout << "Testing primality related algorithms\n";
  cout << "Is 101 prime? " << ProbPrime(101) << "\n";
  cout << "Is 1001 prime? " << ProbPrime(1001) << "\n";
  cout << "Is 8 prime? " << ProbPrime(8) << "\n";
  cout << "Factoring 30030: \n";
  f = trial_factor_complete(to_ZZ(30030 * 13));
  f.print();

  cout << "\n";
  cout << "Testing getter functions which are now pointers\n";
  const vector<ZZ>* ps = f.getPrimes();
  cout << ps->at(0) << "\n";

  cout << "\n";
  cout << "Testing ZZ version of Pocklington\n";
  for (ZZ n = to_ZZ(2); n < to_ZZ(20000); n++) {
	  if (n % 10000 == 0) {
		  cout << "checkpoint: " << n << "\n";
	  }
	  if (ProbPrime(n) != pocklington(n, trial_factor_complete(n - 1))) {
		  cout << n << "\n";
	  }
  }
  */

}
