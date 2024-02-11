#include <iostream>
#include <set>
#include <math.h>
#include "lib.h"


using namespace std;


void task3() {

	multiset<int> tree;

	while (1) {
	
		int num;

		cout << "Please, enter a number: " << endl;

		cin >> num;

		if (num == -1) {
		
			if (tree.size() >= 5) {
			
				cout << *tree.find(5) << endl;
				break;
			}

		} else tree.insert(num);	
	}

	cout << endl;

	for (auto el : tree)
	{
		cout << el << " ";
	}
}