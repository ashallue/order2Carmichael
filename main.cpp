/* Author: Andrew Shallue, May 2020
Constructing order 2 Carmichael numbers
*/

#include <iostream>
#include <cmath>
#include "primality.h"

using namespace std;

int main() {
  std::cout << "Hello World!\n";
  
  // 293084723^239847 mod 1698711 = 571172
  // 293423^12908304 mod 23897425 = 12360991
  cout << mod_power1(293084723, 239847, 1698711) << "\n";
  cout << mod_power2(293084723, 239847, 1698711) << "\n";
  cout << mod_power1(293423, 12908304, 23897425) << "\n";
  cout << mod_power2(293423, 12908304, 23897425) << "\n";
 
  // testing is_prime_fermat with 100, 101, and 102
  cout << "100 is prime: " << is_prime_fermat(100, 2) << "\n";
  cout << "101 is prime: " << is_prime_fermat(101, 2) << "\n";
  cout << "102 is prime: " << is_prime_fermat(102, 2) << "\n";
  
  /*
  for(long i = 2; i < 20; i++){
    if(is_prime_trialdivision(i)){
      cout << i << " is prime\n";
    }else{
      cout << i << " is composite\n";
    }
  }
  */
}
