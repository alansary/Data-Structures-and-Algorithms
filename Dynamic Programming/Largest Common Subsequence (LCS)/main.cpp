#include <iostream>
#include <vector>
using namespace std;

/*
 * LIS Longest Increasing Subsequence
 *
 * Given an array sequence, find the length of the longest subsequence such that all
 * elements of the subsequence are sorted in increasing order.
 *
 * Input: {50, 4, 10, 8, 30, 100}
 * Output: 4
 * Explanation: {4, 8, 30, 100}
 */

// Bottom Up DP

int LIS(vector<int> arr) {
	if (!arr.size()) return 0;

	vector<int> dp(arr.size(), 1);
	dp[0] = 1;

	for (int i = 1; i < arr.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] <= arr[i] && (dp[j] + 1 > dp[i]))
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	return *max_element(dp.begin(), dp.end());
}

int main() {
	vector<int> arr = {50, 4, 10, 8, 30, 100};
	cout << LIS(arr) << endl;

	return 0;
}
