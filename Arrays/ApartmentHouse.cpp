#include <iostream>
#include <string>
#include "lib.h"


using namespace std;


void apartmentHouse() {

	const int apartmentsQ = 10;
	const int apartmentsForCheck = 3;

	string* array = new string[apartmentsQ];

	cout << "Array: " << endl;
	for (size_t i = 0; i < apartmentsQ; i++)
	{
		cout << "Please, enter the name of the " << i + 1 << "th house resident" << endl;
		cin >> array[i];
	}

	int num;

	for (size_t i = 0; i < apartmentsForCheck; i++)
	{
		cout << "Please, enter the number of the apartment: " << endl;
		cin >> num;
		if (0 < num && num <= apartmentsQ)
			cout << array[num - 1] << " lives in the " << num << "th apartment" << endl;
		else
			cout << "Incorrect apartment number... should fit the interval from 1 to " << apartmentsQ << endl;
	}

}
