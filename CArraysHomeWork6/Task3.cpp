#include <iostream>
#include "lib.h"


using namespace std;


bool isSubstr(const char* str1, const char* str2) {

	int j = 0;

	string string1 = static_cast<string>(str1), string2 = static_cast<string>(str2);

	if (string1.length() < string2.length()) return false;

	while (*(str1 + j + string2.length() - 1) != '\0') {
	
		int i = 0;
		bool flag = true;

		while (*(str2 + i) != '\0') {
		
			if (*(str1 + j + i) != *(str2 + i)) {
			
				flag = false;
				break;
			}

			i++;
		}

		if (flag) { 
			cout << "Start index: " << j << endl;
			return true; 
		}

		j++;
	}

	return false;
}


void task3() {

	const char* str1 = "Hi, mister president!";
	const char* str2 = "ter pres";

	cout << "\"" << str2 << (isSubstr(str1, str2) ? "\" is substr of \"" : "\" is not substr of \"") << str1 << "\"" << endl;
}





