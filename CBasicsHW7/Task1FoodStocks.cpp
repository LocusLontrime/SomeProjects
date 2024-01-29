#include <iostream>
#include "lib.h"


using namespace std;


void task1() {

	int buckwheatWeight = 100;
	const int lossPerMonth = 4;
	const int months = buckwheatWeight / lossPerMonth;

	cout << "Initial amount of buckwheat is " << buckwheatWeight << " kg" << endl;

	for (int i = 0; i < months; i++)
	{
		buckwheatWeight -= lossPerMonth;

		cout << "After " << i + 1 << " months " << buckwheatWeight << " kg of buckwheat remained " << endl;
	}
}
