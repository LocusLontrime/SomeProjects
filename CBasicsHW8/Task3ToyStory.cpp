#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;


void task3() {

	const float size = 5;
	const int minCubesSide = 2;

	float x, y, z;

	cout << "Please, enter the bar sizes, separated by space: " << endl;
	cin >> x >> y >> z;

	if (x <= 0 || y <= 0 || z <= 0) {
	
		cout << "All sizes should be greater than zero..." << endl;
		return;
	}

	int cubesQ = (int)(x / size) * (int)(y / size) * (int)(z / size);

	cout << "cubesQ: " << cubesQ << endl;

	int cubesPerSide = (int) pow(cubesQ, 1./3);

	cout << "cubesPerSide: " << cubesPerSide << endl;

	if (cubesPerSide >= minCubesSide) {
	
		cout << pow(cubesPerSide, 3) << " cubes can be made of this bar!" << endl;
	}
	else {
	
		cout << "No game set could be made of this bar..." << endl;
	}
}