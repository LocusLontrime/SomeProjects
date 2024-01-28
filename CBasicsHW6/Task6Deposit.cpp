#include <iostream>
#include "lib.h"


using namespace std;


void task6() {

	int deposit, rate, aim;

	cout << "Please, enter your initial deposit, bank rate and your goal amount separated by space: " << endl;
	cin >> deposit >> rate >> aim;

	if (deposit < 0 && rate < 0 && aim < 0 && deposit <= aim) {
	
		cout << "Remember, that deposit, rate and aim values should be positive and aim should be greater than deposit!!!" << endl;

	}


	int years = 0;
	while (deposit < aim) {
	
		deposit *= (1 + rate / 100.0);

		cout << "Current deposit: " << deposit << endl;

		years++;
	}

	cout << "You must wait " << years << " years to achieve your goal!";

}