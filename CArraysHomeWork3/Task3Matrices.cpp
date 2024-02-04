#include <iostream>
#include "lib.h"


using namespace std;


bool compare(int (*matrix1)[4], int (*matrix2)[4]) {

	for (int j = 0; j < 4; j++) {

		for (int i = 0; i < 4; i++)
		{
			if (matrix1[j][i] != matrix2[j][i]) {

				return false;
			}
		}
	}

	return true;
}


void normalize(int(*matrix)[4]) {

	for (int j = 0; j < 4; j++) {

		for (int i = 0; i < 4; i++)
		{
			if (j != i) 
				matrix[j][i] = 0;	
		}
	}
}


void print(int(*matrix)[4]) {

	for (int j = 0; j < 4; j++) {

		for (int i = 0; i < 4; i++)
		{

			cout << matrix[j][i] << " ";
		}

		cout << endl;
	}
}


void task3() {

	int matrix1[][4] = { 
		{1, 6, 5, 9}, 
		{2, 8, 6, 0},
		{0, 7, 7, 6},
		{1, 6, 0, 9} 
	};

	int matrix2[][4] = {
		/*{1, 4, 5, 2},
		{9, 8, 9, 0},
		{9, 0, 0, 1},
		{2, 7, 6, 9} */
		{1, 6, 5, 9},
		{2, 8, 6, 0},
		{0, 7, 7, 6},
		{1, 6, 0, 9}
	};

	if (compare(matrix1, matrix2)) {

		cout << "Matrix1 is equal to matrix2!\n" << endl;
	
		normalize(matrix1);

		cout << "Diagonalized matrix1: " << endl;
		print(matrix1);

		cout << "Matrix2: " << endl;
		print(matrix2);
	}
	else
		cout << "Matrix1 is equal to matrix2!" << endl;
}





