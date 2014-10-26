#include <iostream>
#include <string>

using namespace std;

// pos can be 1 (units), 10 (tens), 100 (hundreds)...
char getDigit ( int num, int pos= 1 ) {
	return num/pos % 10;
}

string unitsToWord ( char d ) {
	string words[] = {
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	if ( 0 <= d and d <= 9 ) return words[d-1];
	else return "";
}

string tensToWord ( char d ) {
	string words[] = {
		"ten",
		"twenty",
		"thirty",
		"forty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety"
	};

	if ( 1 <= d and d <= 9 ) return words[d-1];
	else return "";
}

// Converts an integer up to a 1000
// to a continuous word (no spaces or hyphens)
string intToWord ( int i ) {
	if ( i <= 9 ) {
		return unitsToWord(i);
	} else if ( i == 10 ) {
		return tensToWord(1);
	} else if ( i < 20 ) {
		string words[] = {
			"eleven",
			"twelve",
			"thirteen",
			"fourteen",
			"fifteen",
			"sixteen",
			"seventeen",
			"eighteen",
			"nineteen"
		};

		return words[i-11];
	} else if ( i < 100 ) {
		string unitsWord = unitsToWord( getDigit(i) );
		string tensWord = tensToWord( getDigit(i, 10) );

		if ( i%10 == 0 ) return tensWord;
		else return tensWord+unitsWord;
	} else if ( i < 1000 ) {
		string restWord = intToWord( i%100 );
		string hundredsWord = unitsToWord(getDigit(i, 100)) + "hundred";

		if ( i%100 == 0 ) return hundredsWord;
		else return hundredsWord+"and"+restWord;
	} else if ( i == 1000 ) {
		return "onethousand";
	}

	return "";
}

// If all the numbers from 1 to 1000 (one thousand) inclusive
// were written out in words, how many letters would be used?
int main () {
	int length = 0;
	for ( int i= 1; i <= 1000; i++ ) {
		length += intToWord(i).length();
	}

	cout << length << endl;
	
	return 0;
}