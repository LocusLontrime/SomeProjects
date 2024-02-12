#include <iostream>
#include "lib.h"


using namespace std;


void inverse(int *array, int lP, int rP) { while (lP < rP) swap(array[lP++], array[rP--]); } // swap func from the 1st task


void printArr(int* array, int length) {

	for (size_t i = 0; i < length; i++) cout << array[i] << " ";

	cout << endl;
}


void task2() {

	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int lP = 0, rP = *(&array + 1) - array;

	cout << "Initial array: " << endl;
	printArr(array, rP);

	cout << "lP, rP: " << lP << ", " << rP << endl;

	inverse(array, lP, rP - 1);

	cout << "Inversed array: " << endl;
	printArr(array, rP);
}





