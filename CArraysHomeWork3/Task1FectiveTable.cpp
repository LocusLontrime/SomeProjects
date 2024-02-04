#include <iostream>
#include "lib.h"


using namespace std;

void task1() {

	// initialization...
	int cutlery[][6] = { // spoons, knives and so on...
		{4, 4, 3, 3, 3, 3}, 
		{3, 3, 3, 3, 3, 3} 
	};

	int plates[][6] = { 
		{3, 3, 2, 2, 2, 2}, 
		{2, 2, 2, 2, 2, 2} 
	};

	int chairs[][6] = { 
		{1, 1, 1, 1, 1, 1}, 
		{1, 1, 1, 1, 1, 1}
	};

	// events handling:
	// 1. chair has been added (1th row, 5th seat)
	chairs[0][4] += 1;
	// 2. spoon has been stolen (2th row, 3th seat)
	cutlery[1][2] -= 1; 
	// 3. Vip person shares his spoon with guest whose spoon has been stolen...
	cutlery[0][0] -= 1; 
	cutlery[1][2] += 1;
	// 4. Waiter took desert plate from Vip seat...
	plates[0][0] -= 1;
}
