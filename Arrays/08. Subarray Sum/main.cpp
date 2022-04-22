#include <iostream>
using namespace std;

// Brute Force Approach O(n^3)
int maximum_subarray_sum(int * arr, int n) {
	int sum;
	int largest_sum = arr[0];

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum = 0;
			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}
			largest_sum = max(sum, largest_sum);
		}
	}

	return largest_sum;
}

int main() {
	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr) / sizeof(int);

	cout << maximum_subarray_sum(arr, n) << endl;

	return 0;
}
