#include <iostream>
#include "lib.h"


using namespace std;


void task6() {  // 366 36 98 989 LL

	int day, month, year;
	int currDay, currMonth, currYear;

	cout << "Please, enter the date of your birthday: " << endl;
	cin >> day >> month >> year;
	cout << "Please, enter the current date: " << endl;
	cin >> currDay >> currMonth >> currYear;

	if (currYear - year > 18 || currYear - year == 18 && currMonth > month ||
		currYear - year == 18 && currMonth == month && currDay >= day) {

		cout << "Congratulations!!! You may drink some alcohol..." << endl;

	}
	else
		cout << "Sorry, but you are not allowed to drink alcohol..." << endl;


}