#include <iostream>
#include <string.h>
#include "lib.h"


using namespace std;


void isRepeated(string str) {

	string doubledStr = str + str;
	string repeatedStr = "";
	int strSize = str.size();

	// candidate searching in doubled str (using lemme of string shift...):
	int j = 0;
	for (int i = 1; i < 2 * strSize; i++)
	{

		/*cout << "(" << j << "," << i << ") -> str[" << j << "], str[" << i << "]: ("
			<< doubledStr[j] << ", " << doubledStr[i] << "), repeated: " << repeatedStr << "" << endl;*/

		if (doubledStr[j] == doubledStr[i]) {

			repeatedStr += doubledStr[i];
			j++;
			int repPossLength = i - j + 1;

			if (j == strSize && repPossLength < strSize) {

				cout << "The string: \"" << str << "\" is the " << strSize / (repPossLength) <<
					"th times repeated word: " << doubledStr.substr(0, repPossLength) << endl;
				return;
			}
		}
		else {

			repeatedStr = "";
			j = 0;
		}
	}

	cout << "The string: \"" << str << "\" is not some repeated string" << endl;
}


void task2() {

	string str;

	cout << "Please, enter your string: " << endl;
	cin >> str;

	isRepeated(str);
}





