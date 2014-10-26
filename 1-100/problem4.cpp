#include <iostream>
#include <cmath>

using namespace std;

// Get the length of an unsinged integer
int unsignedSize ( unsigned long long int num ) {
	for ( unsigned char length = 1; ; length++ ) {
		if ( num < pow(10, length) ) {
			return length;
		}
	}
}

// Pop a digit from a integer
char popDigit ( unsigned long long int &num ) {
	char digit = num % 10;
	num /= 10;

	return digit;
}

// Push a digit to a integer
unsigned long long int pushDigit ( unsigned long long int &num, char digit ) {
	num *= 10;
	num += digit;
}

bool isPalindrome( unsigned long long int num ) {
	int len = unsignedSize(num);
	unsigned long long int lastHalf = 0;

	char digit;
	for ( int i= 0; i < len/2; i++ ) {
		pushDigit( lastHalf, popDigit(num) );
	}

	if ( len%2 == 1 ) popDigit(num);

	return num == lastHalf;
}

int main () {
	unsigned long long int palindrome = 0;

	// Loop through three digit numbers
	// and find the maximum palindrome product
	for ( int A= 100; A < 1000; A++ ) {
		// Initialize B to palindrom/A+1 to ensure that 
		// any number calculated is larger than the palindrome
		for ( int B= palindrome/A+1; B < 1000; B++ ) {
			if ( isPalindrome(A*B) ) {
				palindrome = A*B;
			}
		}
	}

	cout << palindrome << endl;

	return 0;
}