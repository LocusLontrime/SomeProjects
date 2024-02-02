#include <iostream>
#include "lib.h"


using namespace std;


void task6() {

	int array[5][5];

	for (size_t i = 0; i < 25; i++)
	{
		int parity = (i / 5) % 2;
		int k = (5 - parity + (1 - 2 * parity) * (i % 5)) % 5;
		cout << k << " ";

		array[i / 5][k] = i;	
	}

	cout << "Array:\n" << endl;
	for (size_t i = 0; i < 25; i++)
	{
		cout << array[i / 5][i % 5] << " ";
		if (i % 5 == 4)
			cout << endl;
	}
}