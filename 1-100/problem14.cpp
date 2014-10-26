#include <iostream>
#include <cmath>

using namespace std;

// Calculate the total term in the collatz
// sequence of num
int collatzLength ( unsigned long long int num ) {
	int c= 1;

	// Make sure the first number is odd
	while ( num%2 == 0 ) {
		num /= 2;
		c++;
	}

	// Observation: the number can only
	// be one after applying the collatz formula on
	// an even number
	while ( num != 1 ) {
		// Apply the collatz formula
		// on the odd number to get an even number
		num = 3*num+1;
		c++;

		// Apply the collatz forumla recursively
		// on the even number to get an odd
		while ( num%2 == 0 ) {
			num /= 2;
			c++;
		}
	}
	
	return c;
}

// Find the number under 1,000,000 that 
// produces the longest collatz chain
int main () {
	int max = 1000000,
		num = 1,
		maxChain = 0;

	for ( int i= 1; i < max; i++ ) {
		if ( maxChain < collatzLength(i) ) {
			num = i;
			maxChain = collatzLength(i);
		}
	}

	cout << num << endl;

	return 0;
}