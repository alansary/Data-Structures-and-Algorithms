#include <iostream>
#include <vector>
using namespace std;

// Coin Change

/*
 * Given an array of coin denominations, an integer M representing target money.
 * We need to find the min coins required to make the change.
 *
 * Input: Coins = [1, 3, 7, 10], M = 15
 * Output: 3
 * Explanation: 7 + 7 + 1
 */

// Top Down DP
int coinChangeTopDownDP(vector<int> coins, int m, vector<int> dp) {
	if (!m) {
		return 0;
	}

	int minimum = INT_MAX;

	for (int i = 0; i < coins.size(); i++) {
		if (m - coins[i] == 0) {
			return 1;
		} else {
			if (m - coins[i] > 0) {
				if (!dp[m - coins[i]])
					dp[m - coins[i]] = coinChangeTopDownDP(coins, m - coins[i], dp);
				if (dp[m - coins[i]] != -1)
					minimum = min(dp[ m - coins[i]], minimum);
			}
		}
	}

	return minimum == INT_MAX ? -1 : minimum + 1;

}

// Bottom Up DP
int coinChange(vector<int> coins, int m) {
	vector<int> dp(m+1, 0);
	dp[0] = 0;

	int min;
	for (int i = 1; i <= m; i++) {
		min = INT_MAX; // to handle cases where we can't change with given coins
		for (int j = 0; j < coins.size(); j++) {
			if (i - coins[j] >= 0 && dp[i - coins[j]] + 1 < min) {
				min = dp[i - coins[j]] + 1;
			}
		}
		dp[i] = min;
	}

//	for (int i = 0; i < m+1; i++) {
//		cout << i << " ";
//	}
//	cout << endl;
//
//	for (int i = 0; i < m+1; i++) {
//		cout << dp[i] << " ";
//	}
//	cout << endl;

	return dp[m] == INT_MAX ? -1 : dp[m]; // to handle cases where we can't change with given coins
}

int main() {
	vector<int> coins = {1, 3, 7, 10};

	for (int m = 0; m <= 25; m++) {
		cout << coinChange(coins, m) << " ";
	}
	cout << endl;
	for (int m = 0; m <= 25; m++) {
		vector<int> dp(m+1, 0);
		cout << coinChangeTopDownDP(coins, m, dp) << " ";
	}
	cout << endl;

	return 0;
}
