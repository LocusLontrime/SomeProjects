#include <iostream>
#include <string>
#include "lib.h"

using namespace std;


void printNSymbols1(int n, string symbol) {  // I could not import this function from task 4 via lib.h...

	for (int i = 0; i < n; i++)
	{
		cout << symbol;
	}
}


void task6() {

	int headerLength, exclamationMarkQ;

	cout << "Please, enter the overall header length and exclamation marks quantity separated be spaces: " << endl;
	cin >> headerLength >> exclamationMarkQ;

	if (headerLength <= 0 || exclamationMarkQ <= 0 || headerLength < exclamationMarkQ) {
	
		cout << "headerLength and exclamationMarkQ should be greater than zero\n and headerLength should be greater than exclamationMarkQ!" << endl;
		return;
	}

	int leftTildes = (headerLength - exclamationMarkQ) / 2, rightTildes;
	rightTildes = headerLength - exclamationMarkQ - leftTildes;

	printNSymbols1(leftTildes, "~");
	printNSymbols1(exclamationMarkQ, "!");
	printNSymbols1(rightTildes, "~");
}