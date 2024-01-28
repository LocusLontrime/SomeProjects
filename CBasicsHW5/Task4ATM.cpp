#include <iostream>
#include "lib.h"


using namespace std;


void task4() {

	int* banknotes = new int[6] {100, 200, 500, 1000, 2000, 5000};
	int amountClaimed;

	cout << "Please, enter the amount claimed: " << endl;
	cin >> amountClaimed;

	if (!(amountClaimed % banknotes[0])) {
		cout << "You will get: " << endl;

		int i = 5;

		while (amountClaimed) {

			if (amountClaimed >= banknotes[i]) {

				int banknotesQuantity = amountClaimed / banknotes[i];
				cout << banknotesQuantity << " banknotes in " << banknotes[i] << " Rubbles" << endl;

				amountClaimed -= banknotes[i] * banknotesQuantity;
			}
			i--;
		}
	}
	else
		cout << "You cannot get the amount claimed, please change it..." << endl;
	
	
}