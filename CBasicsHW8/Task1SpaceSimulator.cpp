#include <iostream>
#include <math.h>
#include "lib.h"


using namespace std;


void task1() {

	// main pars:
	float f, m, t;

	cout << "Please, enter Force, weight and time separated by space: " << endl;
	cin >> f >> m >> t;

	float a = f / m;

	float x = a * pow(t, 2) / 2;

	cout << "Spaceship covered a distance of " << x << endl; // 366 36 98 989 LL      
}