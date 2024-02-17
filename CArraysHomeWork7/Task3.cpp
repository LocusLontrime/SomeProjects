#include <iostream>
#include <vector>
#include "lib.h"


using namespace std;


void countEvenDigs(long long n, int& ans);


void task3() {

	long long n = 9223372036854775806L;

	int ans = 0;

	countEvenDigs(n, ans);

	cout << "n's even digs quantity: " << ans << endl;
}


void countEvenDigs(long long n, int& ans) {
	
	if (n == 0) return;
	else countEvenDigs(n / 10, ans += ((n % 10) % 2 ? 0 : 1));
}


