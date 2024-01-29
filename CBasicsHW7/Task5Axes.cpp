#include <iostream>
#include <string>
#include "lib.h"


using namespace std;


void task5() {

	int width = 50, height = 20;

	for (int j = 0; j <= height; j++)
	{
		for (int i = 0; i <= width; i++)
		{
			if (j == height / 2 && i == width / 2) {
			
				cout << "+";

			}
			else if (j == height / 2 && i == width) {
			
				cout << ">";

			}
			else if (i == width / 2 && j == 0) {
			
				cout << "^";

			} 
			else if (j == height / 2) {
			
				cout << "-";

			} 
			else if (i == width / 2) {
			
				cout << "|";

			}
			else {
			
				cout << " ";

			}

			if (i == width) {

				cout << endl;

			}
		}
	}

}