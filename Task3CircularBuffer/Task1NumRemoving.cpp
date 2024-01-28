#include <iostream>
#include <vector>
#include "lib.h"


using namespace std;


void task1() {

	int n, x;

	cout << "Please, choose the size of the vector array: " << endl;
	cin >> n;

	vector<int> vArr(n);

	cout << "Now let us fulfil the vector array..." << endl;

	for (size_t i = 0; i < n; i++)
	{

		cout << "Enter the " << i + 1 << "th element: " << endl;
		cin >> vArr[i];

	}

	cout << "Please, enter the element X to be removed from the vector: " << endl;
	cin >> x;

	const int nOfDels = erase(vArr, x);

	cout << nOfDels << " elements \"" << x << "\" have been removed from the vector..." << endl
		<< "Now the vector is: " << endl;

	for (size_t i = 0; i < n - nOfDels; i++)
	{

		cout << vArr[i] << " ";

	}

}