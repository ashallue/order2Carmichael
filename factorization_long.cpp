#include <iostream>
#include <vector>
using namespace std;

class FactorizationLong{
  private:
    //factors of a number
    //a vector of all the prime factors
    //a vector of powers for each factor
    vector<long> factors;
    vector<long> primes; 
    vector<long> powers;
  public:
    //constructor to initialize factors
    FactorizationLong(vector<long> f){
      factors = f;
    }

    //returns all the prime factors of x
    vector<long> getPrimeFactors(){ 
      return primes;
    }

    //returns powers of factors
    vector<long> getPowers(){
      return powers;
    }

    //returns true when the length of vector<long> primes
    //and vector<long> powers are the same
    bool isSameLength(){
      if(primes.size() == powers.size()){
        return true;
      }
      return false;
    }

    //the product of all the factors
    long factorProduct(){
      long product = 1;
      for(long i = 0; i < factors.size(); ++i){
        product *= factors.at(i);
      }
      return product;
    }
};


