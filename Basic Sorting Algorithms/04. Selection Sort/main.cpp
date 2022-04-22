#include <iostream>
using namespace std;

// O(n^2)
void selection_sort(int * arr, int n) {
	// last element will be sorted; thus, looping n - 1 times
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i+1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
}

int main() {
	int arr[] = {-5, 12, 7, 15, 4, -4, 2, 3, 1};
	int n = sizeof(arr) / sizeof(int);

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	selection_sort(arr, n);

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
