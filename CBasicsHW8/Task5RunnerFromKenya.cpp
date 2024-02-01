#include <iostream>
#include <math.h>
#include "lib.h"

using namespace std;

void task5() {
	int distance;

	cout << "Hi, Sam! Please, say how many kilometers you run!" << endl;
	cin >> distance;

	int overallTime = 0;
	int counter = 0;
	while (counter < distance) {
	
		int seconds;
		cout << "How many seconds did it take you to run the your " << ++counter << "th kilometer ? " << endl;
		cin >> seconds;

		if (seconds <= 0) {
		
			cout << "The number of seconds cannot be less than or equal to zero..." << endl;
			counter--;
			continue;
		}

		overallTime += seconds;
	}

	int avgSecondsPerKm = round(1. * overallTime / distance);
	int avgMins = avgSecondsPerKm / 60;
	int secsRem = avgSecondsPerKm - avgMins * 60;

	cout << "Average time per km: " << avgMins << " mins " << secsRem << " seconds" << endl;
}