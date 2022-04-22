#include <iostream>
#include <vector>
using namespace std;

/*
 * Maximum Subarray Sum
 * Implement a function that takes an array as input and returns the maximum subarray sum.
 * Sample Input
 * 1 -2 3 4 4 -2
 * 5 0 -1 0 1 2 -1
 * Sample Output
 * 11
 * 7
 * Explanation: for test case one, A[2...4] is [3, 4, 4] and it has max sum 3 + 4 + 4 = 11,
 * similarly for test case two, answer should be 7.
 * Note: Minimum size of the subarray should be 1.
 */
int maxSumSubarray(vector<int> A) {
	int current_sum = 0;
	int largest_sum = 0;

	// Handle the case where all elements are negative
	int max_number = INT_MIN;
	bool positive_found = false;
	for (auto x : A) {
		if (x > 0) positive_found = true;
		if (x > max_number) max_number = x;
	}
	if (!positive_found) return max_number;

	for (int i = 0; i < A.size(); i++) {
		current_sum += A[i];
		if (current_sum < 0) {
			current_sum = 0;
		}
		largest_sum = max(largest_sum, current_sum);
	}

	return largest_sum;
}

int main() {
	vector<int> A = {1, -2, 3, 4, 4, -2};
	vector<int> B = {5, 0, -1, 0, 1, 2, -1};
	vector<int> C = {-1, -2, -3, -4, -5};

	cout << maxSumSubarray(A) << endl;
	cout << maxSumSubarray(B) << endl;
	cout << maxSumSubarray(C) << endl;

	return 0;
}
