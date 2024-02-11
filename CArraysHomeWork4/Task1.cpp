#include <iostream>
#include <math.h>
#include "lib.h"


using namespace std;


void task1() {

	// int array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int array[] = {1, 2, 15, -98, -7, 11, -1, 0, 7, 98, -11, -117, -7, 77, 1, 6, 98, 101, -200, 107};
	int length = *(&array + 1) - array;
	int currMinSum = array[0];
	int currSum = 0;
	int bestSum = array[0];

	cout << "Array: ";
	for (size_t i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}

	cout << "\nArray's length: " << length << endl;

	for (size_t i = 0; i < length; i++)
	{
		currSum += array[i];
		currMinSum = min(currMinSum, currSum);
		bestSum = max(bestSum, currSum - currMinSum);
	}

	cout << "Max consecutive sum: " << bestSum << endl;
}
