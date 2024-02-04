#include <iostream>
#include "lib.h"


using namespace std;


void print(bool (*bubbleWrap)[12]) {

	cout << "Bubble wrap: " << endl;

	for (size_t j = 0; j < 12; j++) {
	
		for (size_t i = 0; i < 12; i++) {
		
			cout << (bubbleWrap[j][i] ? "o" : "x") << " ";
		}

		cout << endl;
	}

	cout << endl;
}


void burstRegion(bool(*bubbleWrap)[12], int y1, int x1, int y2, int x2, int &counter) {

	for (size_t j = y1; j <= y2; j++)
	{
		for (size_t i = x1; i <= x2; i++)
		{
			if (bubbleWrap[j][i]) {
			
				bubbleWrap[j][i] = false;
				cout << "Pop! (" << j + 1 << ", " << i + 1 << ")" << endl;;
				counter--;
			}	
		}
	}

	cout << endl;
}


void task5() {

	bool bubbleWrap[12][12];

	for (size_t j = 0; j < 12; j++)
		for (size_t i = 0; i < 12; i++)
			bubbleWrap[j][i] = true;

	int counter = 12 * 12;
	while (counter > 0) {

		print(bubbleWrap);

		int y1, x1, y2, x2;
		cout << "Please, enter two coords: top left and bottom right angles of rectangled-area: " << endl;
		cin >> y1 >> x1 >> y2 >> x2;

		// normalizing coords:
		y1--;
		x1--;
		y2--;
		x2--;

		if (y1 < 0 || y1 >= 12 || x1 < 0 || x1 >= 12 || y2 < 0 || y2 >= 12 || x2 < 0 || x2 >= 12 || 
			x1 >= x2 || y1 >= y2) {
		
			cout << "\nInvalid region!!! Please, choose coords from 1 to 12, no zero region allowed, " << endl
				<< "y2 and x2 must be greater than y1 and x1...\n" << endl;
			continue;
		}

		burstRegion(bubbleWrap, y1, x1, y2, x2, counter);
	}

	cout << "All bubble wrap has been bursted!\n" << endl;
	print(bubbleWrap);









}





