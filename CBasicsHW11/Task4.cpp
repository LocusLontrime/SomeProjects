#include <iostream>
#include <set>
#include <string>
#include "lib.h"


using namespace std;


const int length = 3;

set<char> symbs = { 'X', 'O', '.' };

set<int> bins = { 0, 1 };


char checkRowCol(string *board, int j, int num) { // 'X', 'O', '.'

	int counterX = 0, counterO = 0;

	for (size_t i = 0; i < length; i++)
	{
		char ch = board[num ? i : j][num ? j : i];
		
		if (ch == 'X')
			counterX++;
		else if (ch == 'O')
			counterO++;
		else
			break;
	}

	cout << (num ? "Checks col " : "Checks row ") << j << " -> counterX, counterO: " << counterX << ", " << counterO << endl;

	return counterX == 3 ? 'X' : (counterO == 3 ? 'O' : '.');
}


char checkDiag(string* board, int num) { // num = 0 -> common diag and num = 1 -> second one...

	int counterX = 0, counterO = 0;

	for (size_t j = 0, i = 0; j < length; j++, i++)
	{
		if (board[j][num ? 2 - i : i] == 'X')
			counterX++;
		else if (board[j][num ? 2 - i : i] == 'O')
			counterO++;
		else
			break;
	}

	cout << (num ? "Checks diag 2 " : "Checks diag 1 ") << "-> counterX, counterO: " << counterX << ", " << counterO << endl;

	return counterX == 3 ? 'X' : (counterO == 3 ? 'O' : '.');
}


char findWinner(string* board) {

	int xWins = 0, oWins = 0;

	for (int num = 0; num < 2; num++) {
		for (size_t i = 0; i < length; i++) {
			char winner = checkRowCol(board, i, num);

			cout << "Winner: " << winner << endl;

			if (winner != '.') {

				if (winner == 'X') xWins++;
				else oWins++;
			}
		}
	}
	
	for (int num = 0; num < 2; num++) {

		char winner = checkDiag(board, num);

		cout << "Winner: " << winner << endl;

		if (winner != '.') {

			if (winner == 'X') xWins++;
			else oWins++;
		}
	}
		

	cout << "xWins, oWins: " << xWins << ", " << oWins << endl;

	if (xWins + oWins > 1) return '!';

	return xWins + oWins == 0 ? '.' : (xWins == 1 ? 'X' : 'O');
}


bool validateBoard(string* board, int &qX, int &qO) {


	for (size_t j = 0; j < length; j++)
	{
		for (size_t i = 0; i < length; i++)
		{
			if (!symbs.contains(board[j][i])) return false;

			if (board[j][i] == 'X') qX++;
			else if (board[j][i] == 'O') qO++;
		}
	}

	if (!bins.contains(qX - qO)) return false;

	return true;
}


void ticTacToe(string* board) {

	int qX = 0, qO = 0;

	if (!validateBoard(board, qX, qO)) {
	
		cout << "Incorrect!" << endl;

		return;
	}

	char x = findWinner(board);

	cout << "Winner's symbol case -> " << x << endl;

	switch (x) {
	
		case '!':
			cout << "Incorrect!" << endl;
			break;
		case '.':
			cout << "Nobody..." << endl;
			break;
		case 'X':
			if (qX == qO + 1)
				cout << "Petya won!" << endl;
			else
				cout << "Incorrect!" << endl;
			break;
		case 'O':
			if (qX == qO)
				cout << "Vanya won!" << endl;
			else
				cout << "Incorrect!" << endl;
			break;
	}
}


void task4() {
	// 'X' player -> makes first turn!

	string s1, s2, s3;

	cout << "Please, enter 3 strings of Tic Tac Toe game field: " << endl;
	cin >> s1 >> s2 >> s3;

	cout << "Game board: " << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	string board[] = {s1, s2, s3};

	ticTacToe(board);
}



