#include <iostream>
#include <cmath>

using namespace std;

// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.
int main () {
	int a= 1, b = 0;
	double c = 0;
	for ( ; (a+b+c) < 1000; a++) {
		b = a+1;
		c = b+1;
		while ( (a+b+c) < 1000 ) {
			c = sqrt( a*a + b*b );
			b++;
		}

		if ( a+b+int(c) == 1000 ) cout << a << " " << b << " " << c << endl;
		b = a+1;
	}

	// cout << a << " " << b << " " << c << endl;

	return 0;
}