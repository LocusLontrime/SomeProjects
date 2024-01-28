#include <iostream>
#include <vector>
#include "lib.h"


using namespace std;


void task2() {

	vector<float> prices = {17.5, 98.1, 117.5, 989.0, 89.9};
	vector<int> quantities = {1, 5, 5, 3, 6};

	float overallPrice = 0;

	for (size_t i = 0; i < min(prices.size(), quantities.size()); i++)
	{
		overallPrice += prices[i] * quantities[i];
	}

	cout << "Overall price is " << overallPrice << endl;
}