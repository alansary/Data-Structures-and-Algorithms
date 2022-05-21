#include <iostream>
using namespace std;

/*
 * Bubble Sort
 * Implement Bubble Sort Recursively.
 */

void bubble_sort(int * arr, int n) {
	for (int i = 0; i < n - 1; i++) { // last element will be sorted
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void bubble_sort_rec(int * arr, int n) {
	if (n == 0) return;

	for (int j = 0; j < n - 1; j++) {
		if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
	}

	bubble_sort_rec(arr, n - 1);
}

void helper(int * arr, int n, int index) {
	if (index == n - 1) return;

	if (arr[index] > arr[index + 1]) swap(arr[index], arr[index+1]);
	helper(arr, n, index + 1);
}

void bubble_sort_rec_2(int * arr, int n) {
	if (n == 0) return;

	helper(arr, n, 0);

	bubble_sort_rec_2(arr, n - 1);
}

void bubble_sort_rec_3(int * arr, int n, int index) {
	if (n == 0 || n == 1) return;

	// reduce the problem size and reset j to 0
	if (index == n - 1) {
		bubble_sort_rec_3(arr, n - 1, 0);
		return;
	}

	// inner loop
	if (arr[index] > arr[index + 1]) swap(arr[index], arr[index+1]);
	bubble_sort_rec_3(arr, n, index + 1);
}

int main() {
	int arr[] = {5, 7, 2, 3, 5, 8, 2, 7, 6};

	bubble_sort_rec_3(arr, sizeof(arr)/sizeof(int), 0);
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
