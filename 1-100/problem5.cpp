#include <iostream>
#include <map>
#include <cmath>

using namespace std;

// Check if a number is prime
bool isPrime ( unsigned long long int num ) {
	if ( num < 2 ) return false;
	if ( num < 4 ) return true;
	if ( num%2 == 0 ) return false;

	unsigned long int numSqrt = sqrt(num);
	for ( int i= 3; i <= numSqrt; i+= 2 ) {
		if ( num%i == 0 ) {
			return false;
		}
	}

	return true;
}

// Return the prime factors of a number
map<int, int> findPrimeFactors ( unsigned long long int num ) {
	map<int, int> primeFactors;

	for ( int i= 2; i <= num; i++ ) {
			
		// Count how many of this prime factor
		// there are in the number
		while ( num%i == 0 ) {
			if ( primeFactors.find(i) == primeFactors.end() )
				primeFactors[i]= 1;
			else
				primeFactors[i]++;

			num /= i;
		}

	}

	return primeFactors;
}

// Smallest multiple
// What is the smallest positive number that
// is evenly divisible by all of the numbers from 1 to 20?
int main () {
	int maxDivisor = 91235,
		primeFactor,
		count;
	map<int, int> primeFactors,
				  maxPrimeFactors;

	// Find the maximum count of each prime factor
	// of all numbers
	for ( int i= 0; i < maxDivisor; i++ ) {
		primeFactors = findPrimeFactors(i);

		for ( map<int,int>::iterator it = primeFactors.begin(); it != primeFactors.end(); it++ ) {
			primeFactor = it->first;
			count = it->second;

			if (
				maxPrimeFactors.find( primeFactor ) == maxPrimeFactors.end() or
				maxPrimeFactors[ primeFactor ] < count
			   ) {
				maxPrimeFactors[ primeFactor ]= count;
			}

		}
	}

	// Multiply the primes
	unsigned long long int product = 1;
	for ( map<int,int>::iterator it = maxPrimeFactors.begin(); it != maxPrimeFactors.end(); it++ ) {
		product *= pow(it->first, it->second);
	}

	cout << product << endl;
	
	return 0;
}