#include <iostream>
#include <math.h>
#include <string>
#include "lib.h"


using namespace std;


void task10() {

	int a, b;

	cout << "Please, enter a and b separated by space: " << endl;
	cin >> a >> b;

	int sum, diffAbs;

	sum = a + b;
	diffAbs = abs(a - b);

	cout << "Max val is: " << (sum + diffAbs) / 2 << endl;
}