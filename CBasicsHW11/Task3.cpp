#include <iostream>
#include <set>
#include <string>
#include "lib.h"


using namespace std;


const set<char> symbs = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

const int minNum = 0, maxNum = 255;

const char separator = '.';


string getAddressPart(string ipAddressV4, int &ind, int &counter) {

	string part = "";

	while (ind < ipAddressV4.length() && ipAddressV4[ind] != separator) part += ipAddressV4[ind++];

	if (counter == 4 && ipAddressV4[ind] == separator) return "";

	ind++; // jump over the point...

	counter++;

	return part;
}


bool validatePart(string part) {

	cout << "\nValidating Part \"" << part << "\": " << endl;

	// empty part check:
	if (part == "") { 
		cout << "!!!ip part is empty!!!" << endl; 
		return false; 
	}

	// length's check:
	if (part.length() > 3) { 
		cout << "!!!ip's part length is invalid!!!" << endl; 
		return false; 
	}

	// checks for invalid symbs:
	for (char el : part) if (!symbs.contains(el)) { 
		cout << "!!!symbols are incorrect!!!" << endl;
		return false; 
	}

	// leading zeroes and numbers restrs:
	if (part.length() > 1 && part[0] == '0') { 
		cout << "!!!There are some leading zeroes!!!" << endl; 
		return false; 
	}

	if (stoi(part) > maxNum) {
		cout << "!!!Bad values, something is incorrect!!!" << endl;  
		return false; 
	}

	cout << "Correct!" << endl;
}


bool validateIpV4(string ipAddressV4) {

	int ind = 0, counter = 1;

	while (ind < ipAddressV4.length()) if (!validatePart(getAddressPart(ipAddressV4, ind, counter))) return false;

	return true;
}


void task3() {

	// correct ipsV4:
	// string ip = "127.0.0.1";
	// string ip = "255.255.255.255";
	// string ip = "55.77.213.101";

	// incorrect ones:
	// string ip = "255.256.257.258";
	// string ip = "0.55.33.22.";
	// string ip = "10.00.000.0";
	string ip = "23.055.255.033";
	// string ip = "65.123..9";
	// string ip = "a.b.c.d";

	cout << "Ip: " << ip << endl; // 36 366 98 989 LL .................................................................................

	cout << "\n" << (validateIpV4(ip) ? "The current ip is valid!" : "The current ip is not valid...") << endl;
}



