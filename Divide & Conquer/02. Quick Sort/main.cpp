#include <iostream>
using namespace std;

// Quick Sort
// Average case time complexity: O(nlogn)
// Worst case time complexity: O(n^2)
// Assuming no repetitions exist.
void quickSort(int arr[], int start, int end) {
	if (start >= end) return; // One element is already sorted

	// Choose pivot element - last element will be chosen in this implementation
	int index = start;
	for (int i = start; i < end; i++) {
		// Partition - < pivot & > pivot
		if (arr[i] < arr[end]) { // Pivot == end
			swap(arr[index++], arr[i]);
		}
	}
	// Place pivot in the write location
	swap(arr[index], arr[end]);

	// Recursively sort left and write arrays
	quickSort(arr, start, index - 1);
	quickSort(arr, index + 1, end);
}

int main() {
	int arr[] {1, 7, 3, 2, 5, 4, 6, 2};
	quick_sort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
