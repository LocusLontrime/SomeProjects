#include <iostream>
#include <fstream>
#include "lib.h"


using namespace std;


void task2() {

	const int length = 256; // const of string length...

	ifstream f;
	string path = "C:\\Users\\langr\\source\\C_plus_plus_repo\\ConsoleApplication1\\AdvancedTechHW1\\words.txt";
	f.open(path);

	string word;
	char* symbols = new char[length];
	
	while (!f.eof()) {
	
		f.getline(symbols, length);

		cout << symbols << endl;
	}
	
	f.close();
}