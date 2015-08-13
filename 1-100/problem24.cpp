#include <iostream>
#include <algorithm>

using namespace std;

int main () {
	// Current permutation
	int count = 0;
	// Digits array
	int len = 10;
	int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	// Find permutations up to the millionth
	do {} while ( ++count < 1000000 and next_permutation(nums, nums + len) );
	
	// Print millionth permutation
	for (int i= 0; i < len; i++) {
		cout << nums[i];
	}
	cout << endl;

	return 0;
}
