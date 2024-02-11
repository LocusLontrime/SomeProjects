#include <iostream>
#include <map>
#include <math.h>
#include "lib.h"


using namespace std;


void task2() {

	int array[] = {1, -7, 17, 5, 2, -1, 9, 98};
	int length = *(&array + 1) - array;
	int sum = 2;

	// dict for fast solution:
	map<int, int> indices;

	for (size_t i = 0; i < length; i++)
	{
		if (indices.contains(sum - array[i])) {
		
			cout << sum - array[i] << ", " << array[i] << endl;
			break;
		}
		else indices[array[i]] = i;	
	}
}