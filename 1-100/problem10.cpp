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

// Find the sum of all the primes below 2,000,000
int main () {
	int max = 2000000;
	unsigned long long int sum = 0;

	for ( int i= 2; i < max; i++ ) {
		if ( isPrime(i) ) sum += i;
	}

	cout << sum << endl;

	return 0;
}