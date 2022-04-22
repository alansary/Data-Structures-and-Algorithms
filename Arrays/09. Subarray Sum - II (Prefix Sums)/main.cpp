#include <iostream>
using namespace std;

// Prefix Sum Approach O(n^2)
int maximum_subarray_sum(int * arr, int n) {
	int prefix_sums[100] = {0}; // Replace by a vector or a dynamic array instead

	prefix_sums[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefix_sums[i] = prefix_sums[i-1] + arr[i];
	}

	int largest_sum = arr[0];

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int subarray_sum = i == 0 ? prefix_sums[j] : prefix_sums[j] - prefix_sums[i-1];
			largest_sum = max(largest_sum, subarray_sum);
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
