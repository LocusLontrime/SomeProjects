#include <iostream>
#include <string>
#include <functional>
#include "lib.h"


using namespace std;


void printBoard(string** board, int size) {

	cout << "Board: " << endl;

	for (size_t j = 0; j < size; j++) {
	
		for (size_t i = 0; i < size; i++)
		{
			cout << board[j][i] << " ";
		}
	
		cout << "\n" << endl;
	}
}


void checkRow(string **board, const int size, const string *symbs, int turns, bool &cycleStopFlag, int x) {

	int counter = 0;
	for (size_t j = 0; j < size; j++)
	{
		if (board[j][x] == symbs[turns % 2])
			counter++;
	}

	if (counter == size) {

		cout << "Player " << turns % 2 + 1 << "wins!!!\n" << endl;
		cycleStopFlag = true;
	}
}


void checkCol(string** board, const int size, const string* symbs, int turns, bool &cycleStopFlag, int y) {

	int counter = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (board[y][i] == symbs[turns % 2])
			counter++;
	}

	if (counter == size) {

		cout << "Player " << turns % 2 + 1 << "wins!!!\n" << endl;
		cycleStopFlag = true;
	}
}


void checkDiag1(string** board, const int size, const string* symbs, int turns, bool &cycleStopFlag, int nothing) {

	int counter = 0;
	for (size_t j = 0, i = 0; i < size; j++, i++)
	{
		if (board[j][i] == symbs[turns % 2])
			counter++;
	}

	if (counter == size) {

		cout << "Player " << turns % 2 + 1 << "wins!!!\n" << endl;
		cycleStopFlag = true;
	}
}


void checkDiag2(string** board, const int size, const string* symbs, int turns, bool &cycleStopFlag, int nothing) {

	int counter = 0;
	for (size_t j = 0, i = size - 1; j < size; j++, i--)
	{
		if (board[j][i] == symbs[turns % 2])
			counter++;
	}

	if (counter == size) {

		cout << "Player " << turns % 2 + 1 << "wins!!!\n" << endl;
		cycleStopFlag = true;
	}
}


void task2() {

	// board initialization:
	const int size = 3;
	string** board = new string * [size];

	for (size_t i = 0; i < size; i++)
	{
		board[i] = new string[size];
	}

	for (size_t j = 0; j < size; j++) {
	
		for (size_t i = 0; i < size; i++)
		{
			board[j][i] = "_";
		}
	}

	function<void(string**, const int, const string*, int, bool&, int)> funcs[]{checkRow, checkCol, checkDiag1, checkDiag2};

	// important consts:
	const string symbs[] = { "X",  "O" };
	const int maxTurns = size * size;

	// turns counter:
	int turns = 0;

	// main cycle (while is more convenient...):
	bool cycleStopFlag = false;
	while (turns < maxTurns && !cycleStopFlag) {
	
		cout << turns << "th turn:\n" << endl;

		printBoard(board, size);

		int y, x;

		cout << "Player " << turns % 2 + 1 << ", it's your turn! Please, choose the coords (y, x): " << endl;
		cin >> y >> x;
		cout << endl;

		// normalizing y and x:
		y--;
		x--;

		// invalid coords:
		if (y < 0 || x < 0 || y >= size || x >= size) {
			
			cout << "You should choose the correct coordinates! From 1 to " << size << endl;
			continue;
		}

		// another symbol already placed:
		if (board[y][x] != "_") {
		
			cout << "Another symbol has been already placed at this spot, please, choose coords wisely..." << endl;
			continue;
		}

		// functions' args array:
		int funcArgs[] = {x, y, 0, 0};

		// now placing cross or zero:
		board[y][x] = symbs[turns % 2];

		// checks row, col and diags for winning combs:
		for (size_t i = 0; i < 4; i++)
			funcs[i](board, size, symbs, turns, cycleStopFlag, funcArgs[i]);
			
		// turns incrementation:
		turns++;
	}

	if (turns == maxTurns) {
	
		cout << "Draw!!!\n" << endl;
	}

	printBoard(board, size);
}





