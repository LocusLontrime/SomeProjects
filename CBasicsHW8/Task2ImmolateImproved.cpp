#include <iostream>
#include "lib.h"


using namespace std;

void task2() {

	float hp, magicRes;

	cout << "Please, enter Orc's hit points and magic resistence separated by spaces: " << endl;
	cin >> hp >> magicRes;

	if (hp <= 0 || hp > 1 || magicRes <= 0 or magicRes > 1) {
	
		cout << "Hp and megic resistence should be greater than zero and less than or equal to 1..." << endl;
		return;
	}

	while (1) {
	
		float power;
		cout << "\nNow let us define the power of the fire spell: " << endl;
		cin >> power;

		if (power <= 0 or power > 1) {

			cout << "Power should be greater than zero and less than or equal to 1..." << endl;
			continue;
		}

		float damage = power * (1 - magicRes);

		cout << "The final damage of the fire spell: " << damage << endl;

		hp -= damage;
		
		if (hp <= 0) {
		
			cout << "The orc has fallen!" << endl;
			break;
		}
		else {
		
			cout << "The orc's hit points: " << hp << endl;
		}	
	}
}