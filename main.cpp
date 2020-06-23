/* Author: Andrew Shallue, May 2020
Constructing order 2 Carmichael numbers
*/

#include <iostream>
#include <cmath>
#include "primality.h"
#include <vector>
#include "Factorization.h"

using namespace std;
using namespace NTL;

int main() {
  std::cout << "Hello World!\n";
  
  /* This tests don't work, because the longs are too big for 32-bit Windows data type
  // 293084723^239847 mod 1698711 = 571172
  // 293423^12908304 mod 23897425 = 12360991
  cout << mod_power1(293084723, 239847, 1698711) << "\n";
  cout << mod_power2(293084723, 239847, 1698711) << "\n";
  cout << mod_power1(293423, 12908304, 23897425) << "\n";
  cout << mod_power2(293423, 12908304, 23897425) << "\n";
  */
  cout << is_prime_trialdivision(to_ZZ(14039), to_ZZ(23)) << "\n";
  cout << is_prime_trialdivision(to_ZZ(14039), to_ZZ(120)) << "\n";
  
  // Testing Factorization class on 2^5 * 11 * 41^2 * 101 = 59762912
  Factorization f; vector<ZZ> p; vector<ZZ> pow;
  p.push_back(to_ZZ(2)); p.push_back(to_ZZ(11)); p.push_back(to_ZZ(41)); p.push_back(to_ZZ(101));
  pow.push_back(to_ZZ(5)); pow.push_back(to_ZZ(1)); pow.push_back(to_ZZ(2)); pow.push_back(to_ZZ(1));
  f = Factorization(p, pow);

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

}
