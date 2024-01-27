// FractionalCalc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

# include <iostream>
# include <cmath>
# include <numeric>
# include <tuple>

using namespace std;

unsigned int gcd(unsigned int a, unsigned int b) {
	cout << "a, b: " << a << " " << b << "\n";
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

tuple<int, int> normalize(unsigned int a, unsigned int b)
{
	cout << "resNumerator, resDenominator: " << a << " " << b << "\n"
		<< "calculating gcd...";
	unsigned int resGcd = gcd(a, b);
	cout << "gcd: " << resGcd << "\n";
	a /= resGcd;
	b /= resGcd;
	return make_tuple(a, b);
}

tuple<int, int> add(unsigned int aNumerator, unsigned int aDenominator, unsigned int bNumerator, unsigned int bDenominator)
{
	unsigned int resDenominator = aDenominator * bDenominator;
	unsigned int resNumerator = aNumerator * bDenominator + bNumerator * aDenominator;
	tie(resNumerator, resDenominator) = normalize(resNumerator, resDenominator);
	cout << "sum of a and b: " << resNumerator << "/" << resDenominator << "\n";
	return make_tuple(resNumerator, resDenominator);
}

tuple<int, int> substract(unsigned int aNumerator, unsigned int aDenominator, unsigned int bNumerator, unsigned int bDenominator)
{
	unsigned int resDenominator = aDenominator * bDenominator;
	unsigned int resNumerator = aNumerator * bDenominator - bNumerator * aDenominator;
	tie(resNumerator, resDenominator) = normalize(resNumerator, resDenominator);
	cout << "difference of a and b: " << resNumerator << "/" << resDenominator << "\n";
	return make_tuple(resNumerator, resDenominator);
}

tuple<int, int> multiply(unsigned int aNumerator, unsigned int aDenominator, unsigned int bNumerator, unsigned int bDenominator)
{
	unsigned int resDenominator = aDenominator * bDenominator;
	unsigned int resNumerator = aNumerator * bNumerator;
	tie(resNumerator, resDenominator) = normalize(resNumerator, resDenominator);
	cout << "product of a and b: " << resNumerator << "/" << resDenominator << "\n";
	return make_tuple(resNumerator, resDenominator);
}

tuple<int, int> divide(unsigned int aNumerator, unsigned int aDenominator, unsigned int bNumerator, unsigned int bDenominator)
{
	// at first check for zero division:
	if (bNumerator == 0) 
	{
		throw exception("Zero division! bNumerator cannot be equal to Zero!");
	}
	unsigned int resDenominator = aDenominator * bNumerator;
	unsigned int resNumerator = aNumerator * bDenominator;
	tie(resNumerator, resDenominator) = normalize(resNumerator, resDenominator);
	cout << "quotient of a and b: " << resNumerator << "/" << resDenominator << "\n";
	return make_tuple(resNumerator, resDenominator);
}

int main()
{
    // std::cout << "Hello World!\n";
	int aN, aD, bN, bD;
	cout << "Please, enter aN, aD, bN, bD" << endl;
	cin >> aN >> aD >> bN >> bD;
	int rN, rD;
	cout << "Please, choose an operation (1 for addition, 2 for substruction, 3 for multiplication or 4 for division):" << endl;
	int op;
	cin >> op;
	switch (op) 
	{
		case 1:
			tie(rN, rD) = add(aN, aD, bN, bD);
			break;
		case 2:
			tie(rN, rD) = substract(aN, aD, bN, bD);
			break;
		case 3:
			tie(rN, rD) = multiply(aN, aD, bN, bD);
			break;
		case 4:
			tie(rN, rD) = divide(aN, aD, bN, bD);
			break;
		default:
			cout << "Please, enter 1, 2, 3 or 4..." << endl;
	}
	
	cout << "rN, rD: " << rN << " " << rD << endl;
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
