#include <iostream>

using namespace std;

// Find the sum of the numbers on the diagonals in a 1001 by 1001 spiral
int main () {
	int size = 1001,
		sum = 1;,
		inc = 2;
	for (int i= 1; i < size*size; ) {
		for (int k= 0; k < 4; k++) {
			i += inc;
			sum += i;
		}
		inc += 2;
	}

	cout << sum << endl;

	return 0;
}