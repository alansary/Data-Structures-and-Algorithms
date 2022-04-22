#include <iostream>
using namespace std;

// O(n^2)
void bubble_sort(int * arr, int n) {
	// looping n-1 times because the last element will be sorted
	for (int i = 0; i < n - 1; i++) {
		// exclude i sorted elements
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j+1]) {
				// swap
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main() {
	int arr[] = {5, 4, 2, 3, 1};
	int n = sizeof(arr) / sizeof(int);

	bubble_sort(arr, n);

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
