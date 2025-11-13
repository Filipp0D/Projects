#include <iostream>
#include <vector>

using namespace std;

// Bubble Sort
vector<int> bubbleSort(vector<int>& array) {
	int var = 0;
	for (int j = 0; j < array.size() - 1; j++) {

		for (int i = 1; i < array.size() - j; i++) {		// for (int i = 0; i < array.size() - j - 1; i++) {
			if (array[i] < array[i - 1]) {					// if (array[i] < array[i + 1]) {
				var = array[i];
				array[i] = array[i - 1];					// array[i] = array[i + 1];
				array[i - 1] = var;							// array[i + 1] = var;
			}
		}
	}

	return array;
}


// Selection Sorting
vector<int> selectionSort(vector<int>& array) {
	int min_idx = 0;
	for (int i = 0; i < array.size() - 1; i++)			// ...size()-1 perchè l'ultimo posso anche non controllarlo
	{
		min_idx = i;
		for (int j = i + 1; j < array.size(); j++) {
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		swap(array[min_idx], array[i]);
	}

	return array;
}

void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


// Insertion Sorting
vector<int> insertionSort(vector<int>& array) {
	
	for (int i = 1; i < array.size(); i++) {
		int value = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > value) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = value;
	}

	return array;
}



// Quick Sorting
int partition(vector<int>& array, int low, int high) {
	int i = low - 1;
	//high = array.size()-1
	int pivot = array[high];

	for (int j = low; j < high; j++) {
		if (array[j]<pivot)
		{
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[high]);

	return i+1;
}

void quickSort(vector<int>& array, int low, int high) {

	if (low < high)
	{
		int pivot_idx = partition(array, low, high);

		quickSort(array, low, pivot_idx - 1);
		quickSort(array, pivot_idx + 1, high);
	}
}



// Merge Sorting

void merge(vector<int>& array, int low_idx, int high_idx) {
	
	

}


int main()
{

	vector<int> vec = { 5, 3, 1, 8, 9, 2 };

	vec = insertionSort(vec);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}

	return 0;
}

