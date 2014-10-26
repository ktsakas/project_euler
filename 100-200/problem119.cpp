#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define BIG_INT unsigned long long int

using namespace std;

// Pop a digit from a integer
char popDigit ( BIG_INT &num ) {
	char digit = num % 10;
	num /= 10;

	return digit;
}

// Get the length of an unsinged integer
int unsignedSize ( BIG_INT num ) {
	for ( unsigned char length = 1; ; length++ ) {
		if ( num < pow(10, length) ) {
			return length;
		}
	}
}

// Check if a number is equal to the
// sum of it's digits raised to power
BIG_INT sumDigits ( BIG_INT num ) {
	int sum= 0;
	while ( num > 0 ) {
		sum += popDigit(num);
	}

	return sum;
}

// Digit power sum
int main () {
	// Given data
	int A2 = 512,
		A10 = 614656;

	// The maximum number of digits to search for
	// Note: too high and the program might run forever due to an overflow
	int maxDigits = 17,
	// The maximum sum of the above number of digits eg. 99999
		maxSum = maxDigits*9;

	BIG_INT term;
	vector<BIG_INT> sequence;

	// Note: the algorithm does not retrieve
	// the terms of the sequence in order

	// Loop through digitSums
	for ( int digitSum= 2; digitSum < maxSum; digitSum++ ) {

		int power = 0;
		// Make sure the first term has at least 2digits
		do {
			term = pow(digitSum, ++power);
		} while ( unsignedSize(term) == 1 );

		// Loop through the powers
		while ( unsignedSize(term) <= maxDigits ) {

			// If the possible term has a digit sum
			// equal to the one that created it, then it is
			// a term of the sequence
			if ( sumDigits(term) == digitSum ) {
				sequence.push_back( term );
			}

			// Find the next term
			term = pow(digitSum, ++power);
		}
	}

	// Sort the sequence and remove duplicates
	vector<BIG_INT>::iterator it;
	sort( sequence.begin(), sequence.end() );
	it = unique( sequence.begin(), sequence.end() );
	sequence.resize( distance(sequence.begin(), it) );

	// Print the sequence
	int i= 1;
	for ( it = sequence.begin(); it != sequence.end(); it++ ) {
		cout << i++ << ": " << *it << endl;
	}
	
	return 0;
}