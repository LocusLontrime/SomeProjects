#include <iostream>
#include <string>
#include "lib.h"


using namespace std;


void task2() {

	int water, milk;

	cout << "Please, enter the amounts of water and milk in coffee machine separated by space: " << endl;
	cin >> water >> milk;

	if (water < 0 || milk < 0) {
	
		cout << "Water and Milk amounts should be greater than or equal to zero!" << endl;
		return;

	}

	int americanoCups = 0, latteCups = 0;

	while (water >= 300 || water >= 30 && milk >= 270) {
	
		int ans;

		cout << "Please, choose your drink (1 for americano and 2 for latte): " << endl;
		cin >> ans;

		switch (ans) {
			
			case 1:
				if (water >= 300) {
				
					water -= 300;
					cout << "Your americano is ready! " << water << " ml of water and " << milk << " ml of milk remained" << endl;
					americanoCups++;
				}
				else
					cout << "Water is not enough for your americano... try to order latte!" << endl;
				break;

			case 2:
				if (water >= 30 && milk >= 270) {
				
					water -= 30;
					milk -= 270;
					cout << "Your latte is ready! " << water << " ml of water and " << milk << " ml of milk remained" << endl;
					latteCups++;
				} 
				else 
					cout << "Milk is not enough for your latte... try to order americano!" << endl;
				break;

			default:
				cout << "Please, enter 1 or 2..." << endl;
				break;
		}
	}

	cout << "The coffee machine is now off" << endl;

	cout << "The water remained: " << water << "ml" << endl;
	cout << "The milk remained: " << milk << "ml" << endl;

	cout << "Cups of americano: " << americanoCups << endl;
	cout << "Cups of latte: " << latteCups << endl;
}