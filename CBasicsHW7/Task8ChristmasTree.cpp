#include <iostream>
#include <string>
#include "lib.h"


using namespace std;


void printNSymbols2(int n, string symbol) {  // I could not import this function from task 4 via lib.h...

	for (int i = 0; i < n; i++)
	{
		cout << symbol;
	}
}


void task8() {

	int height;

	cout << "Please, enter the height of the Christmas Tree: " << endl;
	cin >> height;

	cout << "\nChristmas Tree:\n" << endl;

	for (int i = 1; i <= height; i++)
	{
		printNSymbols2(height - i, " ");
		printNSymbols2(i * 2 - 1, "#");
		printNSymbols2(height - i, " ");
		cout << endl;
	}
}