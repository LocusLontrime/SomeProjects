#include <iostream>
#include <fstream>
#include <Windows.h>
#include "lib.h"


using namespace std;


void task1() { // 36 366 98 989 LL

	ifstream f;
	string path = "C:\\Users\\langr\\source\\C_plus_plus_repo\\ConsoleApplication1\\AdvancedTechHW1\\words.txt";
	f.open(path);  

	int wordCounter = 0;
	string word;

	cout << "Please, enter the word: " << endl;	
	cin >> word;

	string currentWord;
	while(!f.eof()) {
	
		f >> currentWord;

		if (currentWord == word) wordCounter++;		

		cout << "Current word: " << currentWord << ", counter: " << wordCounter << endl;

		Sleep(100);
	}

	cout << "The word \"" << word << "\" repeats " << wordCounter << " times in the text given..." << endl;
	f.close();
}