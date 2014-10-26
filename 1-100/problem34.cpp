#include <iostream>
#define BIG_INT unsigned long long int

using namespace std;

// Pop a digit from a integer
char popDigit ( BIG_INT &num ) {
	char digit = num % 10;
	num /= 10;

	return digit;
}

int factorial ( int num ) {
	int factorial = 1;
	for ( int i= 2; i <= num; i++ ) factorial *= i;
	return factorial;
}

// Calculate the sum of the factorials of the digits
int digitFactorialSum ( BIG_INT num, int cachedFactorials[] ) {
	int digit,
		sum = 0;
	do {
		digit = popDigit(num);
		sum += cachedFactorials[digit];
	} while ( num > 0 );
	return sum;
}

// Find the sum of all numbers which are equal
// to the sum of the factorial of their digits.
int main () {
	BIG_INT sum= 0;

	// Cache factorials for digits 1-9
	int cachedFactorials[10];
	for ( int i= 0; i < 10; i++ ) 
		cachedFactorials[i] = factorial(i);

	// Note: brute force can be improved
	for ( int i= 10; i < 100000; i++ ) {
		if ( digitFactorialSum(i, cachedFactorials) == i ) sum += i;
	}

	cout << sum << endl;

	return 0;
}