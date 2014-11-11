#include <iostream>
#include <cmath>

using namespace std;

// Count the number of divisors in a number
int countDivisors ( int num ) {
	int divisors = 0;
	double root = sqrt(num);
	for ( int i= 1; i < root; i++ ) {
		if ( num%i == 0 ) divisors += 2;
	}

	if ( floor(root) == root ) divisors++;
	return divisors;
}

// What is the value of the first triangle number to have over five hundred divisors?
int main () {
	int divisors = 0,
		num = 0,
		add = 1;
	do {
		num += add;
		add++;
		divisors = countDivisors(num);
	} while ( divisors <= 500 );

	cout << num << endl;

	return 0;
}