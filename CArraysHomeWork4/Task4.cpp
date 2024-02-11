#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

// just a studying...
struct Fafa
{
	int x;
};

struct Lala
{
	int x, y;
};

bool operator<(Fafa fafa, Lala lala) { return fafa.x < lala.x; };

// the task itself:
void task4() {

	int array[] = { -100, -50, -5, 1, 10, 15 };
	int length = *(&array + 1) - array;

	cout << "Array: ";

	for (size_t i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}

	cout << "\nArray's length: " << length << endl;

	//final array for merging two parts:
	int* newArr = new int[length];

	// two pointers:
	int lP = 0, rP = length - 1;

	while (lP <= rP) // the core of algo...
		if (abs(array[lP]) < abs(array[rP])) newArr[rP-- - lP] = array[rP];
		else newArr[rP - lP++] = array[lP];

	cout << "New array: ";
	for (size_t i = 0; i < length; i++)
	{
		cout << newArr[i] << " ";
	}
}