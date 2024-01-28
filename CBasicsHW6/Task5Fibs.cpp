#include <iostream>
#include "lib.h"


using namespace std;


void task5() {

	long long prev = 1, next = 1;
	int number;

	cout << "Please, enter the N of Fibonacci number (not greater than 92): " << endl;
	cin >> number;

	if (number < 0 || number > 92) { // long long type restriction...

		cout << "N should be greater than zero and less than 93..." << endl;
		return;

	}
		
	int i = 1;
	while (i < number) {
	
		next += prev;
		prev = next - prev;

		i++;
	}

	cout << "Fib number: " << prev << endl;
}