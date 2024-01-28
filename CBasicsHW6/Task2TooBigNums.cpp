#include <iostream>
#include <math.h>
#include "lib.h"


using namespace std;


void task2() {

	int digsQ, num;

	cout << "Please, enter the number: " << endl;
	cin >> num;

	digsQ = num ? log10(num) + 1 : 1;

	cout << "The digits quantity of the number: " << digsQ << endl;
}