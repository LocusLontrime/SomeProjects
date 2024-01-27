#include <iostream>
#include <string>
#include "lib.h"
#include <cassert>


using namespace std;


float travelDistance(float distance, float speed) {

	assert(speed > 0);

	return distance / speed;
}


void assertUsing() {

	int distance, speed;

	cout << "Please, enter the distance and the speed separated by space: " << endl;
	cin >> distance >> speed;

	cout << "Travel time: " << travelDistance(distance, speed) << endl;
}
