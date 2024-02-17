#include <iostream>
#include <vector>
#include "lib.h"


using namespace std;


// a bit of memoization doesn't hurt...
int* memoTable;


int recRabbitJump(int n, int k);


void task2() {

	int n = 29, k = 9;

	memoTable = new int[n + 1];

	for (size_t i = 0; i <= n; i++) memoTable[i] = 0;
	memoTable[0] = 1;

	cout << "Diff ways quantity: " << recRabbitJump(n, k) << endl;
	cout << "Memo table: " << endl;

	for (size_t i = 0; i <= n; i++) cout << memoTable[i] << " ";                     
}


int recRabbitJump(int n, int k) {

	// cout << "n, k: " << n << ", " << k << endl;

	if (memoTable[n]) return memoTable[n];

	for (int i = n - 1; i >= n - k && i >= 0; i--) memoTable[n] += recRabbitJump(i, k);
	
	return memoTable[n];
}

