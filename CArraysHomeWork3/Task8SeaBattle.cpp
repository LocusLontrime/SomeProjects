#include <iostream>

#include "lib.h"


using namespace std;


bool placeShip_(bool** ships1, bool** ships2, int y0, int x0, int y1, int x1, bool dir, bool placementFlag /* true -> forward, false -> inverse*/) {
	// placement flag = true -> common, else -> inverse...
	bool flag = y1 - y0 > x1 - x0;
	int yStart = dir ? y0 : y1, xStart = dir ? x0 : x1;

	for (int i = 0; abs(i) <= (y1 - y0 + x1 - x0); dir ? i++ : i--)
	{
		int y_ = yStart + (flag ? i : 0), x_ = xStart + (!flag ? i : 0);

		if (dir && ships1[y_][x_] != placementFlag && ships2[y_][x_] != placementFlag || !dir) 
			ships1[y_][x_] = placementFlag;
		else 
			return placeShip_(ships1, ships2, y0, x0, y_ - (flag ? 1 : 0), x_ - (!flag ? 1 : 0), !dir, !placementFlag);					
	}

	return dir;
}


// covering:
bool placeShip(bool** ships1, bool** ships2, int y0, int x0, int y1, int x1) {

	return placeShip_(ships1, ships2, y0, x0, y1, x1, true, true);

}


void print(bool** ships) {

	for (size_t j = 0; j < 10; j++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << ships[j][i] << " ";
		}
		cout << "" << endl;
	}
}


void print2(bool** ships1p, bool** ships2p) {

	cout << "Ships1p array: " << endl;
	print(ships1p);

	cout << "Ships2p array: " << endl;
	print(ships2p);

	cout << endl;
}


void placeShips(bool **ships1p, bool **ships2p) {

	int shipsMap[][2] = { {1, 1}, {2, 1}, {3, 1}, {4, 1} };

	for (size_t i = 0; i < 4; i++)
	{
		cout << "Now placing " << shipsMap[i][0] << "-decked ships:\n" << endl;

		int turns = 0;
		while (turns < 2 * shipsMap[i][1]) {

			int y0, x0, y1, x1;

			print2(ships1p, ships2p);

			cout << "Player " << turns % 2 + 1 << " is placing " << turns / 2 + 1 << "th " << shipsMap[i][0] << "-decked ship..." << endl
				<< "\nPlease, enter start and end coords (y0 x0 y1 x1) of the ship you wanna place: " << endl;

			cin >> y0 >> x0 >> y1 >> x1;

			if (x0 >= 0 && x0 < 10 && x1 >= 0 && x1 < 10 && y0 >= 0 && y0 < 10 && y1 >= 0 && y1 < 10 && 
				(y1 == y0 || x1 == x0) && max(y1 - y0, x1 - x0) + 1 == shipsMap[i][0]) {
			
				if (placeShip(turns % 2 ? ships2p : ships1p, turns % 2 ? ships1p : ships2p, y0, x0, y1, x1)) {
				
					turns++;
					cout << "Your ship has been placed succesfully!\n" << endl;

				} else {
				
					cout << "\nA ship cannot cross an another one!!!\n" << endl;
				}	
			}
			else {
			
				cout << "\nCoordinates of the ship must be valid (from 0 to 9) and correcpond the ship's length! Try again...\n" << endl;
			}	
		}
	}
}


bool fire(bool **ships, int y, int x) {
	// true if the ship destroyed else -> false!

	if (ships[y][x])
		return true;
	else
		return false;

}


void task8() {

	// int ships1p[10][10], ships2p[10][10];
	bool **ships1p = new bool *[10]; // ships1p
	bool **ships2p = new bool *[10]; // ships2p

	// initialization:
	for (size_t i = 0; i < 10; i++)
	{
		ships1p[i] = new bool[10];
		ships2p[i] = new bool[10];
	}

	//filling:
	for (size_t j = 0; j < 10; j ++)
	{
		for (size_t i = 0; i < 10; i++)
		{	
			ships1p[j][i] = false;
			ships2p[j][i] = false;
		}
	}

	cout << "The Sea battle begins!!! Players, be well-prepared!!!" << endl;

	cout << "Now player1 and player2 should place all the ships on the board 10x10:\n" << endl;
	placeShips(ships1p, ships2p);

	const int lifes = 1 * 4 + 2 * 3 + 3 * 2 + 4 * 1;
	int lifes1p = lifes, lifes2p = lifes;

	cout << "Now the shooting phase!\n" << endl;

	int turns = 1;
	while (1) {
	
		int yFire, xFire;

		print2(ships1p, ships2p);

		cout << "Player1's lifes: " << lifes1p << ", player2's lifes: " << lifes2p << "\n" << endl;

		cout << (turns % 2 ? 1 : 2) << "th player's turn. Choose the coords to fire (yFire, xFire): " << endl;
		cin >> yFire >> xFire;

		if (yFire >= 0 && yFire < 10 && xFire >= 0 && xFire < 10) {
		
			if (!(turns % 2 ? ships1p : ships2p)[yFire][xFire]) {
			
				if ((turns % 2 ? ships2p : ships1p)[yFire][xFire]) {
				
					cout << "\nYour shot reached the aim!\n" << endl;

					(turns % 2 ? ships2p : ships1p)[yFire][xFire] = false;

					(turns % 2 ? lifes2p : lifes1p)--;
				}
				else {
				
					cout << "\nYou have missed... maybe another time...\n" << endl;
				}

				turns++;

			} else {
			
				cout << "\nDo not shoot yourself!!!\n" << endl;
			}
		}
		else {
		
			cout << "\nInvalid coords! Try again... (must be from 0 to 9)\n" << endl;
		}

		if (!lifes1p) {
		
			cout << "\nPlayer1 has been defeated, congratulations, player2!!!" << endl;
			break;
		} 
		else if (!lifes2p) {
			
			cout << "\nPlayer2 has been defeated, congratulations, player1!!!" << endl;
			break;
		}
	}
}

