#include <iostream>
#include <vector>
using namespace std;

// Elements should be bounded in a small range
// Assuming elements are greater than or equal to zero
// O(n + range)
void counting_sort(int arr[], int n) {
	// largest element
	int largest = -1;

	for (int i = 0; i < n; i++) {
		if (largest < arr[i]) {
			largest = arr[i];
		}
	}

	// frequency array
	vector<int> frequency(largest + 1, 0);
//	int *frequency = new int[largest + 1]; // dynamic array

	for (int i = 0; i < n; i++) {
		frequency[arr[i]] += 1;
	}

	// put back elements from frequency array into original array
	int j = 0;

	for (int i = 0; i <= largest; i++) {
		while (frequency[i] > 0) {
			arr[j++] = i;
			frequency[i]--;
		}
	}
}

int main() {
	int arr[] = {2, 5, 4, 2, 10, 3, 9, 5, 4};
	int n = sizeof(arr) / sizeof(int);
	int max = 100;

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	counting_sort(arr, n);

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
