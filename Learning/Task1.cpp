#include <iostream>
#include "lib.h"
#include <functional>


using namespace std;


// void func(Array3D arr);


class Array3D {

	protected:
		// relative sizes:
		const int k0, j0, i0;

		// // linear equivalent length:
		const int n0;

		// linear equivalent arr:
		int* arr;

	// constructor:
	public:
		Array3D(int k, int j, int i): k0(k), j0(j), i0(i), n0(k * j * i) {

			// a linear array isomorphic to the initial 3 array k0 * j0 * i0:
			arr = new int[n0];
		}

		// method of accessing to array's elements:
		int access(int k, int j, int i) {
		
			return arr[k * (j0 * i0) + j * (i0) + i];
		}

		int set(int k, int j, int i, int val) {
		
			arr[k * (j0 * i0) + j * (i0)+i] = val;
		}

		void fill(int val) {
		
			for (size_t i = 0; i < n0; i++)
			{
				arr[i] = val;
			}	
		}

		int*** getReeal3DArr() {
		
			int*** arrReal3D = new int** [k0];

			for (size_t k = 0; k < k0; k++)
			{
				arrReal3D[k] = new int* [j0];

				for (size_t j = 0; j < j0; j++)
				{
					arrReal3D[k][j] = new int[i0];
				}
			}

			for (size_t n = 0; n < n0; n++)
			{
				int ji = n % (j0 * i0);

				arrReal3D[n / (j0 * i0)][ji / i0][ji % i0] = arr[n];
			}

			return arrReal3D;
		}

		int getk0() {
		
			return k0;

		}

		int getj0() {

			return j0;

		}

		int geti0() {

			return i0;

		}
};

void task1() {

	Array3D arr3D{7, 8, 9};

	arr3D.fill(98); // 36 366 98 989 LL...........................................................................

	cout << "" << arr3D.access(6, 7, 8) << endl;

	int*** arrReal3D = arr3D.getReeal3DArr();

	cout << "Real 3D array: " << endl;
	for (size_t k = 0; k < arr3D.getk0(); k++)
	{
		for (size_t j = 0; j < arr3D.getj0(); j++)
		{
			cout << "...";
			for (size_t i = 0; i < arr3D.geti0(); i++)
			{
				cout << arrReal3D[k][j][i] << " ";
			}

			cout << endl;
		}

		cout << endl;
	}

	// func(arr3D);
}


//void func(Array3D arr) {
//
//	// check...
//
//}