#include <iostream>
#include <cmath>
#include <algorithm>

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

unsigned long long int calcMaxPrimeFactor ( unsigned long long int num ) {
	if ( isPrime(num) ) return num;

	unsigned long long int maxPrimeFactor = 0;
	unsigned int numSqrt = sqrt(num);
	bool isPrimeA, isPrimeB;

	// Loop possible factors of the number
	// from greatest to smallest
	for ( int i= 2; i <= numSqrt; i++ ) {
		// If i is a factor
		// it is a couple with num/i
		if ( num%i == 0 ) {

			isPrimeA = isPrime(i);
			isPrimeB = isPrime(num/i);

			if ( isPrimeA and isPrimeB ) {
				int m = max(i, int(num/i));
				if ( maxPrimeFactor < m ) maxPrimeFactor= m;
			} else if ( isPrimeA ) {
				if ( maxPrimeFactor < i ) maxPrimeFactor= i;
			} else if ( isPrimeB ) {
				if ( maxPrimeFactor < num/i ) maxPrimeFactor= num/i;
			}

		}
	}

	return maxPrimeFactor;
}


// Find the maximum prime factor of 600851475143
int main () {
	unsigned long long int num = 123;

	cout << calcMaxPrimeFactor( num ) << endl;

	return 0;
}