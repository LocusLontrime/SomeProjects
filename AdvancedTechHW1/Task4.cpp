#include <iostream>
#include <fstream>
#include <Windows.h>
#include "lib.h"
#include <vector>


using namespace std;


void task4() {
	const int length = 256; // const of string length...

	ifstream f;
	string path = "C:\\Users\\langr\\source\\C_plus_plus_repo\\ConsoleApplication1\\AdvancedTechHW1\\Lastar.png";

	f.open(path, ios::binary);

	char* s = new char[4];

	f.read(s, 4);

	// cout << static_cast<int>(s[0]) << endl;
	// cout << s[1] << s[2] << s[3] << endl;

	static_cast<int>(s[0]) == -119 && s[1] == 'P' && s[2] == 'N' and s[3] == 'G' ? 
		cout << "File is PNG" << endl : cout << "File is not PNG" << endl;
}


