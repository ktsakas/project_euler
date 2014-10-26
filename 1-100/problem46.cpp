#include <iostream>
#include <cmath>

using namespace std;

// Check if a number is prime
bool isPrime ( unsigned long long int num ) {
	unsigned long int numSqrt = sqrt(num);

	for ( int i= 2; i <= numSqrt; i++ ) {
		if ( num%i == 0 ) {
			return false;
		}
	}

	return true;
}

// Checks if goldbachs other proposed
// conjecture which is false
// holds for a given number
bool conjectureHolds ( int num ) {
	if ( isPrime(num) or num%2 == 0 ) return true;

	// Loop through primes
	for ( int prime= 2; prime < num; prime++ ) {
		if ( isPrime(prime) ) {
			int squareBase = 1,
				formula;

			// Loop though square bases
			do {
				formula = prime + 2 * squareBase*squareBase;
				squareBase++;
			} while ( formula < num );

			if ( formula == num ) return true;
		}
	}

	return false;
}

// Goldbach's other conjecture
// What is the smallest odd composite
// that cannot be written as the sum of a prime and twice a square?
int main () {
	int i= 2;
	for ( ; conjectureHolds(i); i++ );

	cout << i << endl;
	
	return 0;
}