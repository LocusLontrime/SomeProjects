#include <iostream>

#include <set>
#include <string>

#include "lib.h"


using namespace std; // 36 366 98 989 LL ..................................................................................


const int length = 3;

set<char> symbs = { 'X', 'O', '.' };

set<int> bins = { 0, 1 };


char checkRowColDiag(string *board, int j, int num) { // 'X', 'O', '.'

	int counterX = 0, counterO = 0;

	int djdi[][2] = { {0, 1}, {0, 1},  {1, 1}, {1, -1} };
	int coords[][2] = { {j, 0}, {0, j}, {j, 0}, {j, 2} };
	string phrases[] = {"Checks col ", "Checks row ", "Checks diag 1 ", "Checks diag 2 " };

	for (; (num ? coords[num][0] : coords[num][1]) < length ;)
	{
		char ch = board[coords[num][0]][coords[num][1]];
		
		if (ch == 'X')
			counterX++;
		else if (ch == 'O')
			counterO++;
		else
			break;

		for (int k = 0; k < 2; k++) // a step of the outer cycle...
			num == 1 ? coords[num][(1 + k) % 2] += djdi[num][k] : coords[num][k] += djdi[num][k];
	}

	string str = phrases[num];
	if (num < 2)
		str += to_string(j);

	cout << str << " -> counterX, counterO: " << counterX << ", " << counterO << endl;

	return counterX == 3 ? 'X' : (counterO == 3 ? 'O' : '.');
}


char findWinner(string* board) {

	int xWins = 0, oWins = 0;

	for (int num = 0; num < 4; num++) {
		for (size_t i = 0; i < (num < 2 ? length : 1); i++) {
			char winner = checkRowColDiag(board, i, num);

			cout << "Winner: " << winner << endl;

			if (winner != '.') {

				if (winner == 'X') xWins++;
				else oWins++;
			}
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



