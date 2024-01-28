#include <iostream>
#include "lib.h"


using namespace std;


void task1() {

	int speed, height;

	cout << "Please, enter the plane's speed and height of the flight separated by space: " << endl;
	cin >> speed >> height;

	if (750 <= speed && speed <= 850 && 9000 <= height && height <= 9500)
		cout << "The right echelon!" << endl;
	else
		cout << "Wrong echelon!!!" << endl;

}