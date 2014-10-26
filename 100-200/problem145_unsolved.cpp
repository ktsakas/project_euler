#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Reverses the order of the digits of an integer
bool reverseDigits ( int n ) {
	int reversed = 0;
	while (n > 0) {
		reversed = reversed * 10 + (n % 10);
		n /= 10;
	}

	return reversed;
}

// How many reversible numbers are there below one-billion?
int main () {

	return 0;
}