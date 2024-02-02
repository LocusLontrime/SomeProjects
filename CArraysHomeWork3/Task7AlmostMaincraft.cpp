#include <iostream>
#include "lib.h"


using namespace std;


void task7() {

	// for illustrative purposes:
	int heightMap[5][5];

	for (size_t i = 0; i < 25; i++)
	{
		cout << "Please, enter (" << i / 5 << ", " << i % 5 << ") element: " << endl;
		cin >> heightMap[i / 5][i % 5];
	}

	cout << "\nHeightMap:" << endl;
	for (size_t i = 0; i < 25; i++)
	{
		cout << heightMap[i / 5][i % 5] << " ";
		if (i % 5 == 4)
			cout << endl;
	}

	// now the array itself:
	int array[5][5][10];

	for (size_t j = 0; j < 25; j++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			if (i < heightMap[j / 5][j % 5])
				array[j / 5][j % 5][i] = 1;
			else
				array[j / 5][j % 5][i] = 0;
		}
	}

	int sliceNumber;
	cout << "Please, enter the number of the slice you wanna see: " << endl;
	cin >> sliceNumber;

	cout << "\n" << sliceNumber << "th slice:" << endl;
	for (size_t i = 0; i < 25; i++)
	{
		cout << array[i / 5][i % 5][sliceNumber] << " ";
		if (i % 5 == 4)
			cout << endl;
	}
}