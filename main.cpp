/* Author: Andrew Shallue, May 2020
Constructing order 2 Carmichael numbers
*/

#include <iostream>
#include <cmath>
#include "primality.h"
#include <vector>

using namespace std;

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
  
}
