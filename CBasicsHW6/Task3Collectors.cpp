#include <iostream>
#include <string>
#include "lib.h"


using namespace std;


void task3() {

	string name;
	int debtAmount;

	cout << "Please, enter your name and amount of the debt: " << endl;
	cin >> name >> debtAmount;

	if (debtAmount < 0) {
	
		cout << "Your have the negative debt... does not it mean that the bank should pay to you?..";
		return;

	}

	while (debtAmount) {

		int currentPayment;
	
		cout << "Please, pay off the debt... the debt remained: " << debtAmount << endl
			<< "Enter the amount you can pay at the time being: " << endl;
		cin >> currentPayment;

		if (currentPayment >= 0) {
		
			if (currentPayment >= debtAmount) {
			
				cout << "Your debt has been payed off! Now your account balance equals: " << 
					currentPayment - debtAmount << endl;
				debtAmount = 0;

			} else {
			
				debtAmount -= currentPayment;
				cout << "Your payed off the part of your debt..." << endl;

			}
		
		}
		else {

			cout << "How dare you pay the negative amount???";

		}
	}
}