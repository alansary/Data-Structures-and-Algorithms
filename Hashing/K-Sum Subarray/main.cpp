#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * K-Sum Subarray
 *
 * In this challenge, we are given an array and we need to find out the length of longest
 * subarray whose sum is equal to given integer K.
 *
 * Sample Input: arr = {0, -2, 1, 2, 3, 4, 5, 15, 10, 5}, K = 15
 * Sample Output: 5
 * Explanation: The following subarray has the sum 15 and is the longest. {1, 2, 3, 4, 5}
 *
 * Expected Complexity: O(n)
 * Hint: Use prefix_sums + unordered_map.
 */

int longestSubarrayKSum(vector<int> arr, int k) {
    int n = arr.size();
	unordered_map<int,int> m;

	int prefix_sum = 0;
	int len = 0;

	for (int i = 0; i < n; i++) {
		// Prefix sum
		prefix_sum += arr[i];

		// Check if prefix sum accumulates to K starting from index 0
		if (prefix_sum == k) {
			len = max(len, i + 1);
		}

		// prefix_sum - (some number) = k
		// prefix_sum - k = (some number)
		// if (some number) exists; then sum up to k exists
		if (m.find(prefix_sum - k) != m.end()) {
			len = max(len, i - m[prefix_sum - k]);
		}
		else {
			// Store prefix sum in hashmap
			m[prefix_sum] = i;
		}

	}

	return len;

}

int main() {
	vector<int> arr = {0, -2, 1, 2, 3, 4, 5, 15, 10, 5};
	int K = 15;

	cout << longestSubarrayKSum(arr, K) << endl;

	return 0;
}
