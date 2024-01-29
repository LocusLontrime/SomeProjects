#include <iostream>
#include <string>
#include "lib.h"


using namespace std;


void task3() {

	const int maxX = 15, maxY = 20;

	// initial state:
	int x = 7, y = 10;

	while (1) {
	
		string ans;
		cout << "Mars rover coords: (" << x << ", " << y << "). Please, choose the direction(WASD)" << endl;
		cin >> ans;

		if (ans == "W") {
		
			if (y < maxY)
				y++;

		}
		else if (ans == "A") {
			
			if (x > 0)
				x--;

		}
		else if (ans == "S") {
		
			if (y > 0)
				y--;

		}
		else if (ans == "D") {
		
			if (x < maxX)
				x++;

		}
		else {
		
			cout << "Wrong direction! Choose the one from WASD..." << endl;

		}

	}

}