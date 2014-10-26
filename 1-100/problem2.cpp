#include <iostream>
#include <ctime>

using namespace std;

// Even Fibonacci numbers
// By considering the terms in the Fibonacci
// sequence whose values do not exceed four 
// million, find the sum of the even-valued terms.
int main () {
	int max = 4000000,
		F1 = 1,
		F2 = 2,
		tmp,
		sum = 0;

	while ( F2 < max ) {
		sum += F2;

		// Skip odd fibionacci
		do {
			tmp = F1;
			F1 = F2;
			F2 = tmp+F1;
		} while ( F2%2 == 1 );
	}

	cout << sum << endl;

	return 0;
}