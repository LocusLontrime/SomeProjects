#include <iostream>
#include <string>
#include "lib.h"


using namespace std;


void task8() {

	// old good binary search can do this in log2(n) ops...

	int ops = 0;
	int min, max;

	cout << "Please, define min and max borders of number guessing -> enter 2 values separated by space: " << endl;
	cin >> min >> max;

	if (min < 0 || max < 0 || min > max) {
	
		cout << "Min and max values should be greater than zero and max cannot be less than min!" << endl;
		return;

	}

	while (1) {
		ops ++;
	
		int pivotEl = (min + max) / 2;
		string ans;

		cout << "Min and max now are: " << min << " | " << max << endl;
		cout << "Is " << pivotEl << " your number? (Enter Y/N)" << endl;;
		cin >> ans;

		if (ans == "Y") {
		
			cout << "Your number guessed in " << ops << " ops!" << endl;
			break;

		}
			
		cout << "Is your number greater than " << pivotEl << "? (Enter Y/N)" << endl;
		cin >> ans;

		if (ans == "Y") {
		
			min = pivotEl + 1;
		
		}
		else {
		
			max = pivotEl - 1;
		
		}

	}

}