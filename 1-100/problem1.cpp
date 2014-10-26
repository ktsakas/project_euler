#include <iostream>

using namespace std;

// Sum of all multiples of 3 and 5 under 1000
int main () {
	int max = 1000;
	int sum = 0;

	// Add multiples of 3
	for ( int i= 3; i < max; i+= 3 ) sum += i;

	// Add multples of 5
	// that are not multiples of three
	for ( int i= 5; i < max; i+= 5 ) {
		if ( i%3 != 0 ) sum += i;
	}
	
	cout << sum << endl;

	return 0;
}