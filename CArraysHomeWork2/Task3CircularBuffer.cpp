#include <iostream>
#include <vector>
#include "lib.h"


using namespace std;


void task3() {

	const int size = 20;

	// circular buffer (cb) of size = 20 for ex:
	vector<int> cb(size);

	int elems = 0, startPointer = 0;

	// operation cycle:
	while (1) {
		// simple and fast:
		int val;

		cout << "Please, enter the value to add: " << endl;
		cin >> val;

		if (val == -1) {
		
			// if val == -1 -> we should print the circular buffer:
			cout << "Circular buffer: " << endl;

			for (size_t i = 0; i < size; i++)
			{
				cout << cb[((elems == size ? startPointer : 0) + i) % size] << " ";
			}

			cout << endl;

		}
		else if (val < -1) {

			// -1 is reserved, let us suppose that values must be positive or equal to zero:
			cout << "Value should be positive or equal to zero!" << endl;
		
		}
		else {
		
			// common case, adding the val to the circular buffer:
			cout << "Appending the value of " << val << endl;

			cb[startPointer++ % size] = val;

			if (elems < size)
				elems++;
		}
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
