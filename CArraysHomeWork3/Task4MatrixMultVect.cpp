#include <iostream>
#include "lib.h"


using namespace std;


void task4() {

	int matrix[][4] = {
		{1, 6, 5, 9},
		{2, 8, 6, 0},
		{0, 7, 7, 6},
		{1, 6, 0, 9}
	};

	int vector[] = {6, 2, 4, 9};

	int result[4] = {};

	// multiplication:
	for (int j = 0; j < 4; j ++) {

		result[j] = 0;
	
		for (int i = 0; i < 4; i++)
			result[j] += matrix[j][i] * vector[i];	
	}

	cout << "Result: " << endl;
	for (size_t i = 0; i < 4; i++)
	{
		cout << result[i] << "" << endl;
	}
}





