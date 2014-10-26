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

// Find the 10,001st prime
int main () {
	int order = 10001,
		count = 0,
		prime = 1;

	while ( count != order ) {
		prime++;
		if ( isPrime(prime) ) count++;
	}

	cout << prime << endl;

	return 0;
}