#include <iostream>
#include <string>
#include "lib.h"

using namespace std;


void task7() {

	int t = 10;

	int n, x;

	cout << "Please, enter n and x: " << endl;
	cin >> n >> x;

	while (n > 0 && t > 0) {
	
		// bacteria population increasing:
		n *= 2;

		// antibiotic kills bacteria:
		n -= x * t--;

		// showing the info:
		cout << 10 - t << " hours passed, bacteria population: " << (n > 0 ? n : 0) << endl;
	}
}