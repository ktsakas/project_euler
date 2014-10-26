#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


// Check if a number is prime
bool isPrime ( int num ) {
	if ( num < 2 ) return false;
	if ( num < 4 ) return true;
	if ( num%2 == 0 ) return false;
	
	int numSqrt = sqrt(num);
	for ( int i= 3; i <= numSqrt; i+= 2 ) {
		if ( num%i == 0 ) {
			return false;
		}
	}

	return true;
}

int digits2Int ( int digits[], int len ) {
	int result = 0;
	for ( int i= 0; i < len; i++ ) {
		result += digits[i] * pow(10, len-i-1);
	}

	return result;
}

// What is the largest n-digit pandigital prime that exists?
int main () {
	int tmp, maxPandigital = -1;
	for ( int len= 9; len > 0 and maxPandigital == -1; len-- ) {
		// Fill array with digits from largest to smallest
		int nums[len];
		for ( int i= 0; i < len; i++ ) nums[i] = len-i;

		// Loop though pandigitals (permutations)
		// from largest to smallest and if it is a prime exit
		// this is the solution
		do {
			tmp = digits2Int(nums, len);
			if ( isPrime(tmp) ) {
				maxPandigital = tmp;
				break;
			}
		} while ( prev_permutation(nums, nums+len) );
	}

	cout << maxPandigital << endl;

	return 0;
}