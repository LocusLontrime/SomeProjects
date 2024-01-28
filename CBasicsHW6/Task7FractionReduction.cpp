#include <iostream>
#include "lib.h"


using namespace std;



long long getGcd(long long a, long long b) {

	cout << "a, b: " << a << " " << b << "\n";

	if (b == 0) 
		return a;

	return getGcd(b, a % b);
}


void task7() {

	long long numerator, denominator;

	cout << "Please, enter the numerator and denominator of the fraction separated by space: " << endl;
	cin >> numerator >> denominator;

	if (denominator <= 0) {

		cout << "Denominator cannot be less or equal to zero!!!" << endl;
		return;

	}

	if (!numerator) {

		cout << "The fraction reduced: 0";
		return;
	
	}
		
		

	long long gcd = abs(getGcd(numerator, denominator));

	cout << "gcd of num and den: " << gcd << endl;

	cout << "The fraction reduced: " << numerator / gcd;

	if (gcd != denominator)
		cout << "/" << denominator / gcd;
	cout << endl;
}