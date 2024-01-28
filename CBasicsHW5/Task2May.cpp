#include <iostream>
#include "lib.h"


using namespace std;


void task2() {

	int day;

	cout << "Please, enter the number of the day: " << endl;
	cin >> day;

	int rem = day % 7;

	if (!rem || rem == 6 || 1 <= day && day <= 5 || 8 <= day && day <= 10)
		cout << "Day off!!!";
	else
		cout << "Working day..." << endl;

}