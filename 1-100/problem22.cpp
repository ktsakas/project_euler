#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Calculate the score of a name
int calcScore ( string str, int pos ) {
	int alphabetValue = 0;
	for ( int i= 0; i < str.length(); i++ ) {
		alphabetValue += str[i]-64;
	}

	return alphabetValue*pos;
}

// Names scores
// What is the total of all the name scores in the file?
int main () {
	ifstream input("names.txt");
	string names[6000];

	// Ignore first "
	input.ignore(1);
	// Read names
	int length = 0;
	for ( ; getline(input, names[length], '"'); length++ ) {
		input.ignore(2);
	}

	sort(names, names+length);

	// Calculate the sum of the scores
	int sum = 0;
	for ( int i= 0; i < length; i++ ) {
		sum += calcScore(names[i], i+1);
	}

	cout << sum << endl;
	
	return 0;
}