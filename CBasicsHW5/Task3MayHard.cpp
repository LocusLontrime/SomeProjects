#include <iostream>
#include "lib.h"


using namespace std;


void task3() {

	int day, shift;

	cout << "Please, enter the number of the day of the week May starts with: " << endl;
	cin >> shift;
	cout << "Please, enter the number of the day in May : " << endl;
	cin >> day;

	int rem = day % 7;

	// parentheses are remained for the better comprehension:
	if (rem == 7 - (shift - 1) || rem == 6 - (shift - 1) || 1 <= day && day <= 5 || 8 <= day && day <= 10)
		cout << "Day off!!!";
	else
		cout << "Working day..." << endl;

}