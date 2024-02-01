#include <iostream>
#include <math.h>
#include "lib.h"


using namespace std;


void task6() {  // 36 366 98 989 LL

	const float linearAttenuation = 0.084;

	int initialAmplitude, finalAmplitude;

	cout << "Please, enter initial and final amplitudes separated by space: " << endl;
	cin >> initialAmplitude >> finalAmplitude;

	int swingsQ = log2(initialAmplitude / finalAmplitude) / log2(1 + linearAttenuation);

	cout << "The pendulum will swing " << swingsQ << "times..." << endl;

	cout << "Num: " << pow(1 + linearAttenuation, 28 + 1) << endl;
}