#include <iostream>
#include "lib.h"
#include <windows.h>


using namespace std;


void task3() {

	int mins, secs;

	cout << "Please, enter minutes and seconds, separated by space: " << endl;
	cin >> mins >> secs;

	while (mins || secs) {
	
		Sleep(1000);
	
		if (secs) {
		
			secs--;
		
		}
		else {
		
			mins--;
			secs = 59;
		}

		cout << mins << " : " << secs << endl;
	}

	cout << "DING! DING! DING!" << endl;
}
