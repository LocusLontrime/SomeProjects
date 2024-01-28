#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

void task4() {

long long ticketNumber;

	// my compiler defines max long lons val as 2^63 - 513... this val is always near 2^63 - 1, often less.
	cout << "Please, enter the number of your ticket: (number has to be less than " << (long long) (pow(2, 63) - 513) << ")" << endl;
	cin >> ticketNumber;

	int digsQ = ticketNumber ? log10(ticketNumber) + 1 : 1;

	cout << "Your ticket has " << digsQ << " digits..." << endl;

	if (digsQ % 2)
		cout << "Ticket has odd number of digits...";
	else {

		int i = 0;
		int leftSum = 0, rightSum = 0;

		while (ticketNumber) {
		
			int digit = ticketNumber % 10;
			// cout << "digit: " << digit << endl;
			ticketNumber /= 10;

			if (i < digsQ / 2)
				rightSum += digit;
			else
				leftSum += digit;

			i++;
		}

		cout << "l and r sums: " << leftSum << " | " << rightSum << endl;




		
		
		if (leftSum == rightSum)
			cout << "You have the golden ticket! Congratulations!" << endl;
		else
			cout << "You have just a usual ticket..." << endl;

	}







	






}