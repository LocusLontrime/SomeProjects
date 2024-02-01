#include <iostream>
#include <math.h>
#include "lib.h"


using namespace std;


void task8() {

	float w, d, n;
	const float decrement = 0.8;
	const int maxIters = 20;

	cout << "Please, enter w, d, n parameters separated by space: " << endl;
	cin >> w >> d >> n;

	int i = 0;
	while (n > 0 && w > 0 and i < maxIters) {
	
		n = round(2. * n - n * d / w);
		d *= decrement;

		cout << i++ + 1 << "th iteration -> n, d: " << n << ", " << d << endl;
	}
}




