#include <iostream>
#include <algorithm>

using namespace std;

int daysInMonth ( int month, int year ) {
	int thirtyDay[] = {3, 5, 8, 10};
	bool hasThirtyDays = find(thirtyDay, thirtyDay+4, month) != (thirtyDay + 4);

	if ( month == 1 ) {
		// Is leap year?
		if ( year % 400 == 0 or (year % 100 != 0 and year % 4 == 0) ) {
			return 29;
		} else {
			return 28;
		}
	} else if ( hasThirtyDays ) {
		return 30;
	} else {
		return 31;
	}
}

// Count how many Sundays fell on the first of the month
// during the twentieth century (1 Jan 1901 to 31 Dec 2000)
int main () {
	// Indexes 0-6 represent days from Sunday to Saturday
	// Jan 1 of 1901 is a Tuesday so 2
	int firstDay = 2,
		sundays = 0;
	for ( int year = 1901; year <= 2000; year++ ) {
		for ( int month = 0; month < 12; month ++ ) {
			if ( firstDay == 0 ) sundays++;

			// Find first day of the next month
			firstDay = (firstDay + daysInMonth(month, year)) % 7;
		}
	}

	cout << sundays << endl;

	return 0;
}