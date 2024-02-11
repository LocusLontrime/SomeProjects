#include <iostream>
#include <set>
#include <string>
#include "lib.h"


using namespace std;

const int minL = 1, maxLeftL = 64, maxRightL = 63;

const char separator = '@'; // 36 366 98 989 LL ............................................................................................... 

const char symbs[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.";
const char auxSymbs[] = "!#$%&'*+-/=?^_{|}~`";

set<char> symbsSet;

set<char> auxSymbsSet;


bool checkSep(char *email) { return strchr(email, separator) ? true : false; }


int getSepInd(char* email) {

	int sepInd = 0;
	for (size_t i = 0; i < *(&email + 1) - email; i++)
	{
		if (email[i] == separator) {

			sepInd = i;
			break;
		}
	}

	return sepInd;
}


bool checkLeft(char* email, int sepInd) {

	if (email[0] == '.' || email[sepInd - 1] == '.')
		return false;

	for (size_t i = 0; i < sepInd; i++)
	{
		if (i < sepInd - 1 && email[i] == '.' && email[i + 1] == '.') return false;

		if (!symbsSet.contains(email[i]) && !auxSymbsSet.contains(email[i])) return false;
	}
}


bool checkRight(char* email, int sepInd, int len) {

	if (email[sepInd + 1] == '.' || email[len - 1] == '.')
		return false;

	for (size_t i = sepInd + 1; i < len; i++)
	{
		if (i < len - 1 && email[i] == '.' && email[i + 1] == '.') return false;

		if (!symbsSet.contains(email[i])) return false;
	}
}


bool checkEmail(char* email, int len) { 

	cout << "Email: " << email << endl;

	bool containsSep = checkSep(email);
	cout << "Email contains @: " << containsSep << endl;
	if (!containsSep) return false;

	int sepInd = getSepInd(email);
	cout << "Separator's index: " << sepInd << endl;

	// lengths check:
	if (sepInd > maxLeftL || len - 1 - sepInd > maxRightL)
		return false;

	return sepInd != 0 && sepInd != len - 1 && checkLeft(email, sepInd) && checkRight(email, sepInd, len); 
}


void task2() {

	// symbols sets building:
	for (char el : symbs)
		symbsSet.insert(el);

	for (char el : auxSymbs)
		auxSymbsSet.insert(el);

	// correct email:
	// char email[] = "disposable.style.email.with+symbol@example.com";
	// char email[] = "simple@example.com";
	// char email[] = "fully-qualified-domain@example.com";
	// char email[] = "user.name+tag+sorting@example.com";
	// char email[] = "example@s.example";
	// char email[] = "mailhost!username@example.org";
	// char email[] = "user%example.com@example.org";

	//incorrects ones:
	// char email[] = "Abc.example.com";
	// char email[] = "A@b@c@example.com";
	char email[] = "1234567890123456789012345678901234567890123456789012345678901234+x@example.com";

	cout << (checkEmail(email, *(&email + 1) - email) ? "Email is valid! " : "Email is not valid...") << endl;
}



