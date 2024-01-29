#include <iostream>
#include <string>
#include "lib.h"


using namespace std;


void printNSymbols(int n, string symbol) {

	for (int i = 0; i < n; i++)
	{
		cout << symbol;
	}
}

void printSec(string symb1, int length, string symb2) {

	cout << symb1;
	printNSymbols(length, symb2);
	cout << symb1 << endl;

}


void task4() {

	int width, height;

	cout << "Please, enter the width and height of the frame separated by space: " << endl;
	cin >> width >> height;

	if (width < 2 || height < 2) {
	
		cout << "Width and Height should be equal to or greater than 2, error!" << endl;
		return;
	}

	printSec("|", width - 2, "-");

	for (int i = 0; i < height - 2; i++)
	{
		printSec("|", width - 2, " ");
	}

	printSec("|", width - 2, "-");
}