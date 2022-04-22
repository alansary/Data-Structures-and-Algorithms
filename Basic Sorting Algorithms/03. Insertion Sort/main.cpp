#include <iostream>
using namespace std;

// O(n^2)
void insertion_sort(int * arr, int n) {
	// first element is sorted
	for (int i = 1; i < n; i++) {
		int current = arr[i];
		int prev = i - 1;
		while (prev >= 0 && arr[prev] > current) {
			// shift element to the right
			arr[prev+1] = arr[prev];
			prev--;
		}
		// insert the element in the empty location
		arr[prev+1] = current;
	}
}

int main() {
	int arr[] = {5, 4, 1, 3, 2};
	int n = sizeof(arr) / sizeof(int);

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	insertion_sort(arr, n);

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
