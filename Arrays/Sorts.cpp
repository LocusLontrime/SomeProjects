#include <iostream>
#include "lib.h"


using namespace std;


// recursive counter:
int recCounter;


// array filler:
void fillArrayRandomly(int* arr, int size) {
	// fills the array randomly...
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 1000;
	}
}

//--------------------------------HEAP SORT O(n*log(n))------------------------------------------------------------------------------------------

void heapify(int *arr, int size, int ind) {
	// step of counter:
	recCounter += 1;

	// cout << "ind: " << ind << endl;

	// indexes of leafs:
	int leftLeaf = 2 * ind + 1, rightLeaf = 2 * ind + 2;
	int largestElInd = ind;

	// if the left leaf value is larger than the value in the root:
	if (leftLeaf < size && arr[leftLeaf] > arr[largestElInd])
		largestElInd = leftLeaf;

	// if the right leaf value is larger than the value in the root:
	if (rightLeaf < size && arr[rightLeaf] > arr[largestElInd])
		largestElInd = rightLeaf;

	// if there is at least one value in leafs that is bigger than root val:
	if (largestElInd != ind) {
		// swaps the elements of array, so as the largest one should be in the root:
		int temp = arr[ind];
		arr[ind] = arr[largestElInd];
		arr[largestElInd] = temp;
		// heapifying (keeps heap invariant):
		heapify(arr, size, largestElInd);
	}
}

// in-place, stable sort...
void heapSort(int *arr, int size) {
	// building the max heap structure:
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(arr, size, i);
	}
	
	// excluding the elements :
	for (int i = size - 1; i >= 0; i--) {
		// swapping (moving current root to the end):
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		// heapifying:
		heapify(arr, i, 0);
	}
}

//--------------------------------ASCENDING SHIFTING HEAP SORT O(n*log(n))-----------------------------------------------------------------------

// here we find the leaf of the heap built with the max array's element
int topDownMaxLeafSearch(int* arr, int size, int upperInd) {
	// step of counter:
	recCounter += 1;

	// here we start:
	int currInd = upperInd;

	// indexes of leafs:
	int leftLeafInd = currInd * 2 + 1;
	int rightLeafInd = currInd * 2 + 2;

	// checks if the right leaf exists:
	if (rightLeafInd >= size) {
		if (leftLeafInd < size)
			return leftLeafInd;
		else
			return currInd;
	}

	// compares two leafs' values:
	if (arr[leftLeafInd] > arr[rightLeafInd])
		return topDownMaxLeafSearch(arr, size, leftLeafInd);
	else
		return topDownMaxLeafSearch(arr, size, rightLeafInd);
}


// locate the root at the place of the first leaf that is bigger than the root itself
// and then shifts all the parent nodes on the one level higher
void bottomUpRootSifting(int* arr, int size, int upperInd) {
	// finds the max leaf position:
	int currInd = topDownMaxLeafSearch(arr, size, upperInd);

	// ascending until the first bigger:
	while (arr[currInd] < arr[upperInd]) {
		// proceeding to the parent(on the one level higher)
		currInd = (currInd - 1) / 2;
	}

	// memorizes the curr_indexand locate the upper leaf at the place of current leaf:
	int memoizedCurrentLeaf = arr[currInd];
	arr[currInd] = arr[upperInd];

	// now shifting all the leafs on the one level higher:
	while (currInd > upperInd) {
		// proceeding to the parent(on the one level higher):
		currInd = (currInd - 1) / 2;
		// swaps the leafs' values:
		int temp = arr[currInd];
		arr[currInd] = memoizedCurrentLeaf;
		memoizedCurrentLeaf = temp;
	}
}

// in-place, stable sort...
void ascendingSiftingSort(int* arr, int size) {
	// border case:
	if (!size) {
		cout << "The array is empty, there is nothing to sort" << endl;
		return;
	}

	// building a heap, using the ascending sifting :
	// (there is no need to sift the elements with no descendants)
	for (int i = (size - 2) / 2; i >= 0; i--) {
		bottomUpRootSifting(arr, size, i);
	}

	// building the sorted array:
	for (int lastIndex = size - 1; lastIndex > 0; lastIndex--) {
		// locate the current maximum of the heap at the end of it:
		int temp = arr[lastIndex];
		arr[lastIndex] = arr[0];
		arr[0] = temp;
		// then make a step of heapifying:
		bottomUpRootSifting(arr, lastIndex, 0);
	}
}

//-------------------------HOARE PARTITION QUICK SORT O(n*log(n))--------------------------------------------------------------------------------

// Hoare's partition part, auxiliary to main method
int hoarePartition(int *arr, int leftBorder, int rightBorder, int pivotEl) {

	while (1) {
		// skipping the elements that stayed at their place on the left side:
		while (arr[leftBorder] < pivotEl) {
		
			// step of counter:
			recCounter += 1;
		
			leftBorder += 1;
		}
			
		// skipping the elements that stayed at their place on the right side:
		while (arr[rightBorder] > pivotEl) {
		
			// step of counter:
			recCounter += 1;
		
			rightBorder -= 1;
		}
			
		// we are swapping two elements if they are both stay at wrong places:
		if (leftBorder < rightBorder) {
			int temp = arr[leftBorder];
			arr[leftBorder] = arr[rightBorder];
			arr[rightBorder] = temp;
			leftBorder += 1;
			rightBorder -= 1;
		}
		else
			return rightBorder;

		// step of counter:
		recCounter += 1;
	}

}

// fast in-place recursive quick sort with Hoare's partition (NOT STABLE):
void recursiveQuickSort(int *arr, int leftBorder, int rightBorder) {

	// border case of array of 1 element:
	if (leftBorder == rightBorder)
		return;

	// at first, we define the pivotElement(median):
	int pivotEl = (arr[leftBorder] + arr[rightBorder]) / 2;

	// Hoare's Partition, here we're finding the pivotIndex:
	int pivotInd = hoarePartition(arr, leftBorder, rightBorder, pivotEl);

	// recursive tree building, divide and conquer tactics:
	recursiveQuickSort(arr, leftBorder, pivotInd);
	recursiveQuickSort(arr, pivotInd + 1, rightBorder);
}


// just a usable covering:
void quickSort(int* arr, int size) {
	recursiveQuickSort(arr, 0, size - 1);
}

//--------------------------------------MERGE SORT O(n*log(n))-----------------------------------------------------------------------------------

void merge(int *leftArr, int *rightArr, int lSize, int rSize, int *mergedArr) {
	// two pointers strategy:
	int lP = 0, rP = 0;

	// while no array is finished:
	while (lP < lSize && rP < rSize) {
		// the least one is added to the final array:
		if (leftArr[lP] < rightArr[rP]) {
			mergedArr[lP + rP] = leftArr[lP];
			lP += 1;
		}
		else {
			mergedArr[lP + rP] = rightArr[rP];
			rP += 1;
		}

		// step of counter:
		recCounter += 1;
	}

	// now we're adding the elements remained in one of arrays to the resulting one...

	// the case in which the elements remained in the left array:
	for (; lP < lSize; lP++) {
		mergedArr[lP + rP] = leftArr[lP];

		// step of counter:
		recCounter += 1;
	}

	// the case in which the elements remained in the right array:
	for (; rP < rSize; rP++) {
		mergedArr[lP + rP] = rightArr[rP];

		// step of counter:
		recCounter += 1;
	}
}

int* recursiveMergeSort(int *arr, int lInd, int rInd) {

	// base case:
	if (lInd == rInd) {
		int* auxArr = new int[1];
		auxArr[0] = arr[lInd];
		return auxArr;
	}
		
	// pivot index (median):
	int pivotInd = (lInd + rInd) / 2;

	// cout << "pivot index: " << pivotInd << endl;

	// left and right arrays building (recurrent defining of a new left and right arrays):
	int* leftArr = recursiveMergeSort(arr, lInd, pivotInd);
	int* rightArr = recursiveMergeSort(arr, pivotInd + 1, rInd);

	// merging left and right sorted array into one sorted array:
	int* mergedArr = new int[rInd - lInd + 1];
	merge(leftArr, rightArr, pivotInd - lInd + 1, rInd - pivotInd, mergedArr);

	// returns merged sorted array:
	return mergedArr;
}

// just a suitable covering:
int* mergeSort(int *arr, int size) {
	// not in place, but stable...
	return recursiveMergeSort(arr, 0, size - 1);
}

//----------------------SIMPLE BUBBLE SORT O(n^2)------------------------------------------------------------------------------------------------

void bubbleSort(int *arr, int size) {
	// main cycle:
	for (size_t j = size - 1; j > 0; j--)
	{
		for (size_t i = 0; i < j; i++)
		{
			if (arr[i] > arr[i + 1]) {
				// swapping i and i + 1 elements:
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;

				// 'rec' step:
				recCounter += 1;
			}
		}
	}
}


void sortsComparison(int n)
{
	// n -> array size:
    int* array = new int[n]; // dynamic memory allocation... 

	cout << "Initial array size: " << n << "\n" << endl;

	int t1 = clock();

	fillArrayRandomly(array, n);

	// some diff sort methods comparison:
	int t2 = clock(); 
	cout << "Random array filling req " << (t2 - t1) << " ms" << "\n" << endl;

	recCounter = 0;
	heapSort(array, n);  // 213ms for 10^6

	int t3 = clock();
	cout << "Heap Sort time: " << (t3 - t2) << " ms" << endl;
	cout << "rec counter: " << recCounter << "\n" << endl;

	fillArrayRandomly(array, n);
	t3 = clock();
	recCounter = 0;
	ascendingSiftingSort(array, n); // 236ms for 10^6 -->> should be faster than common heap sort, maybe because of bad optimization on c++ lang...

	int t4 = clock();
	cout << "Ascending Sifting Heap sort time: " << (t4 - t3) << " ms" << endl;
	cout << "rec counter: " << recCounter << "\n" << endl;

	fillArrayRandomly(array, n);
	t4 = clock();
	recCounter = 0;
	quickSort(array, n); // 75ms for 10^6 (unstable, but really fast...)

	int t5 = clock();
	cout << "Quick Sort Hoare time: " << (t5 - t4) << " ms" << endl;
	cout << "rec counter: " << recCounter << "\n" << endl;

	fillArrayRandomly(array, n);
	t5 = clock();
	recCounter = 0;
	array = mergeSort(array, n); // 353ms for 10^6

	int t6 = clock();
	cout << "Merge Sort time: " << (t6 - t5) << " ms" << endl;
	cout << "rec counter: " << recCounter << "\n" << endl;

	cout << "Do you wanna wait until the buble sort has finished its work?.. if so press 'Y' (it may take long):\n";
	string answer;
	cin >> answer;
	if (answer == "Y") {

		fillArrayRandomly(array, n);
		t6 = clock();
		recCounter = 0;
		bubbleSort(array, n); // O(n^2) runtime, too slow in comparison with linearithmic sorts...

		int t7 = clock();
		cout << "Bubble Sort time: " << (t7 - t6) << " ms" << endl;
		cout << "rec counter: " << recCounter << "\n" << endl;
	}	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


