#include <iostream>
#include "lib.h"


using namespace std;


void swap(int &a, int &b) {

	int temp = a;
	a = b;
	b = temp;

}


void task1() {

	int a = 98, b = 98989;

	cout << "a, b: " << a << ", " << b << endl;

	cout << "swapping..." << endl;
	swap(a, b);

	cout << "a, b: " << a << ", " << b << endl;
}





