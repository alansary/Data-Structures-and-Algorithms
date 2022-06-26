#include <iostream>
#include <vector>
using namespace std;

/*
 * Knapsack Problem
 *
 * Given weights and prices of n items, we need to put a subset of items in a bag of
 * capacity W such that we get the maximum total value in the bag, also know as knapsack.
 *
 * Input: N = 4, W = 11, wts = {2, 7, 3, 4}, prices = {5, 20, 20, 10}
 * Output: 40
 */

// Top Down DP
int knapsack(vector<int> wts, vector<int> prices, int w, int n) {
	if (!n || !w) return 0;

	int inclusion_profit = 0;
	if (w - wts[n-1] >= 0) {
		inclusion_profit = prices[n-1] + knapsack(wts, prices, w - wts[n-1], n-1);
	}
	int exclusion_profit = 0 + knapsack(wts, prices, w, n-1);

	return max(inclusion_profit, exclusion_profit);
}

// Bottom Up DP
int knapsackBU(vector<int> wts, vector<int> prices, int W, int N) {
	// w (remaining weight) and n (remaining elements) change each time
	vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

	for (int n = 1; n <= N; n++) {
		for (int w = 1; w <= W; w++) {
			int inc = 0, exc = 0;
			// nth item exists at index n-1 in wts and prices arrays
			if (wts[n-1] <= w) {
				inc = prices[n-1] + dp[n-1][w - wts[n-1]];
			}
			exc = dp[n-1][w];

			dp[n][w] = max(inc, exc);
		}
	}

	return dp[N][W];
}

int main() {
	int n = 4;
	int w = 11;
	vector<int> wts = {2, 7, 3, 4};
	vector<int> prices = {5, 20, 20, 10};

	cout << knapsack(wts, prices, w, n) << endl;
	cout << knapsackBU(wts, prices, w, n) << endl;

	return 0;
}
