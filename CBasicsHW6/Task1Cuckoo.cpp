#include <iostream>
#include "lib.h"


using namespace std;


void task1() {

	int hour;

	cout << "Please, enter the hour: " << endl;
	cin >> hour;

	if (1 <= hour && hour <= 12) {
	
		for (int i = 0; i < hour; i++)
		{
			cout << "Cuckoo!!!" << endl;
		}

	}

}