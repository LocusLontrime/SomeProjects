// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <array>
#include <vector>
#include <set>
#include "lib.h"

using namespace std;

int main() {

	int numberOFTask;

	cout << "Please, enter the number of task (1-4): " << endl;
	cin >> numberOFTask;
	cout << endl;
	switch (numberOFTask) {
		case 1:
			// task 1 "Apartment House"
			apartmentHouse();
			break;
		case 2:
			// task 2 "Sorts implementations and comparison in terms of time":
			sortsComparison(1000000); // takes size of an array...
			break;
		case 3:
			// task 3 "Assert using"
			assertUsing();
			break;
		case 4:
			// task 4 "Row of Numbers"
			rowOfNumbers();
			break;
		default:
			cout << "Please enter the number of task from 1 to 4..." << endl;
			break;

	}

	

	

	

	
}