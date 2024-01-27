// FractionsSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Exercise 2.9
# include <iostream>
# include <cmath>
# include <numeric>

using namespace std;

unsigned int gcd(unsigned int a, unsigned int b) {
	cout << "a, b: " << a << " " << b << "\n";
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}


int main() {
	unsigned int aNumerator, aDenominator, bNumerator, bDenominator;
	cout << "Please, enter a's numerator and denominator:\n";
	cin >> aNumerator >> aDenominator;
	cout << "Please, enter a's numerator and denominator:\n";
	cin >> bNumerator >> bDenominator;
	unsigned int resDenominator = aDenominator * bDenominator;
	unsigned int resNumerator = aNumerator * bDenominator + bNumerator * aDenominator;
	cout << "resNumerator, resDenominator: " << resNumerator << " " << resDenominator << "\n"
		<< "calculating gcd...";
	unsigned int resGcd = gcd(resNumerator, resDenominator);
	cout << "gcd: " << resGcd << "\n";
	resNumerator /= resGcd;
	resDenominator /= resGcd;
	cout << "sum of a and b: " << resNumerator << "/" << resDenominator << "\n";
}