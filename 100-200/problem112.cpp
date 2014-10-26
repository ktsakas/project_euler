#include <iostream>

using namespace std;

void getLastDigits ( int &num, int &nextToLastDig, int &lastDig ) {
	lastDig = num%10;
	num /= 10;
	nextToLastDig = num%10;
}

bool isBouncy ( int n ) {
	int lastDig, nextToLastDig;

	// Remove duplicate digits, until you reach
	// different digits
	do {
		getLastDigits(n, nextToLastDig, lastDig);
	} while ( lastDig == nextToLastDig );

	// Working from right to left
	
	// Possibly increasing number
	if ( nextToLastDig < lastDig ) {
		do {
			getLastDigits(n, nextToLastDig, lastDig);
		} while ( n != 0 and nextToLastDig <= lastDig );			
	// Possibly decreasing number
	} else if ( nextToLastDig > lastDig ) {
		do {
			getLastDigits(n, nextToLastDig, lastDig);
		} while ( nextToLastDig >= lastDig );
	}

	return n != 0;
}

// Find the least number for which the proportion of bouncy numbers is exactly 99%
int main () {
	int count = 0, num = 100;
	double percent;
	while ( percent != 0.99 ) {
		num++;
		if ( isBouncy(num) ) count++;
		percent = (double) count/num;
	}
	cout << num << endl;

	return 0;
}