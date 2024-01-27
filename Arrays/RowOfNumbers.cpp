#include <iostream>
#include "lib.h"


using namespace std;


// runtime -> O(n), memory usage -> o(1)...
int getRepeatedOne(int *arr, int size) {
	// min element and overall sum of the array:
	int minEl = arr[0], sum = 0;
	// defines minEl and sum in cycle:
	for (size_t i = 0; i < size; i++)
	{
		if (minEl > arr[i])
			minEl = arr[i];
		sum += arr[i];
	}
	// the repeated one is the diff between overall sum of the array elements and sum of consequtive elements from min to max = min + size - 1:
	return sum - ((minEl + size - 2) * (minEl + size - 1) / 2 - (minEl - 1) * minEl / 2);
}


void rowOfNumbers() { 

	const int size = 15;
	const int k = 98;

	// in the example given:
	int array[size] = { 114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118 };

	cout << "Repeated el: " << getRepeatedOne(array, size) << endl;
}