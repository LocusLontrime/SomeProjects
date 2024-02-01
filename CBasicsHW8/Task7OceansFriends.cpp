#include <iostream>
#include <math.h>
#include "lib.h"


using namespace std;


void task7() {

	int n, k;
	float t;

	cout << "Please, enter n, k, t separated by space: " << endl;
	cin >> n >> k >> t;

	float time = pow(k, n) * t;

	cout << "Overall time: " << time << endl;
}