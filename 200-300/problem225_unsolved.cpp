#include <iostream>

using namespace std;

// Fill array with tribonacci terms
void tribonacciTerms ( unsigned long long int terms[], int len ) {
	terms[0] = terms[1] = terms[2] = 1;
	for ( int i= 3; i < len; i++ ) {
		terms[i] = terms[i-1] + terms[i-2] + terms[i-3];
	}
}

// Check if num divides a value of the array
bool dividesValue ( int num, unsigned long long int nums[], int len ) {
	for ( int i= 0; i < len; i++ ) {
		if ( nums[i]%num == 0 ) {
			return true;
		}
	}
	return false;
}

int main () {
	int len = 140;
	unsigned long long int terms[len];
	tribonacciTerms( terms, len );
	/*for ( int i= 0; i < len; i++ ) {
		cout << terms[i] << endl;
	}*/

	cout << dividesValue(27, terms, len) << endl;
	/*int occurence = 124,
		nonDivisor,
		count = 0;
	for ( int i= 1; count != occurence; i+= 2 ) {
		if ( !dividesValue(i, terms, len) ) {
			nonDivisor = i;
			count++;
		}
	}
	cout << nonDivisor << endl;*/
	
	return 0;
}