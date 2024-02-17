#include <iostream>
#include <vector>
#include "lib.h"


using namespace std;


void swapvec(vector<int>& vec, int* arr);                                                                                                                                      

template <typename T>

void print(T array, int length) {

	for (size_t i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}


void task1() {

	int length = 12;

	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

	int* arr = new int[length] {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	cout << "Initial vec and arr: " << endl;
	
	print(vec, length);
	print(arr, length);

	swapvec(vec, arr);

	cout << "Final vec and arr: " << endl;
	print(vec, length);
	print(arr, length);
}


void swapvec(vector<int>& vec, int* arr) {
	int length = vec.size();

	cout << "Length: " << length << endl;

	for (size_t i = 0; i < length; i++) {
	
		int temp = vec[i];
		vec[i] = arr[i];
		arr[i] = temp;
	}
}




