#include <iostream>
#include <windows.h>
#include "lib.h"

using namespace std;


void task4() {

	float fileSizeMb, downloadSpeedMbPerS;
	float downloadedSizeMb = 0;

	cout << "Please, enter the file size in megabytes\nand the speed of your internet connection separated by space: " << endl;
	cin >> fileSizeMb >> downloadSpeedMbPerS;

	int counter = 0;
	while (downloadedSizeMb < fileSizeMb) {
	
		Sleep(1000);

		downloadedSizeMb += downloadSpeedMbPerS;

		if (downloadedSizeMb > fileSizeMb)
			downloadedSizeMb = fileSizeMb;

		cout << ++counter << " seconds elapsed. Downloaded " << downloadedSizeMb << " of " << fileSizeMb << "(" 
			<< (int) (100 * downloadedSizeMb / fileSizeMb) << "%)." << endl;
	}
}