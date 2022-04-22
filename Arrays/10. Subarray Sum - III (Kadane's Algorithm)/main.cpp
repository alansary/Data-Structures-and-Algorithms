#include <iostream>
using namespace std;

// Kadane's Algorithm O(n)
int maximum_subarray_sum(int * arr, int n) {
	int current_sum = 0;
	int largest_sum = 0;

	// Handle the case where all elements are negative
	int max_number = INT_MIN;
	bool positive_found = false;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) positive_found = true;
		if (arr[i] > max_number) max_number = arr[i];
	}
	if (!positive_found) return max_number;

	for (int i = 0; i < n; i++) {
		current_sum += arr[i];
		if (current_sum < 0) {
			current_sum = 0;
		}
		largest_sum = max(largest_sum, current_sum);
	}

	return largest_sum;
}

int main() {
	int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
	int n = sizeof(arr) / sizeof(int);

	cout << maximum_subarray_sum(arr, n) << endl;

	return 0;
}
