#include <iostream>
#include <fstream>
#include "lib.h"
#include <vector>


using namespace std;


void task3() {

	const int length = 256; // const of string length...

	ifstream f;
	string path = "C:\\Users\\langr\\source\\C_plus_plus_repo\\ConsoleApplication1\\AdvancedTechHW1\\Data.txt";
	f.open(path);

	vector<string> names;

	int currPayment, maxPayment = 0, ind;
	string date;
	int paymentsDone = 0;

	int i = 0;
	while (!f.eof()) {

		string name, surname;

		f >> name >> surname;
		
		names.push_back(name + " " + surname);

		f >> currPayment;

		paymentsDone += currPayment;

		if (currPayment > maxPayment) {

			maxPayment = currPayment;

			ind = i;
		}

		f >> date;

		i++;
	}

	cout << "Payments done: " << paymentsDone << endl;

	cout << "Max payment beneficiar: " << names[ind] << endl;
}