#include <iostream>

using namespace std;

// Find the difference between the sum of the squares of the
// first one hundred natural numbers and the square of the sum.
int main () {
	int sumOfSquares = 0,
						   squareOfSum = 0;
	for ( int i= 1; i <= 100; i++ ) {
		sumOfSquares += i*i;
		squareOfSum += i;
	}
	squareOfSum = squareOfSum*squareOfSum;

	cout << squareOfSum-sumOfSquares << endl;

	return 0;
}