#include <iostream>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(1)

long long int fib(int n) {
	if (n == 0 || n == 1) {
		return n;
	}

	return fib(n-1) + fib(n-2);
}

// Top Down DP: Recursion + Memoization Approach
// In Top Down DP, we start building the big solution
// by explaining how we build it from smaller solutions.
// Time Complexity: O(n)
// Space Complexity: O(n)

long long int fibTopDownDP(int n, int dp[]) {
	// Basecase
	if (n == 0 || n == 1) {
		return n;
	}

	// Check if the state is already computed
	if (dp[n]) {
		return dp[n];
	}

	// Otherwise, compute the state and store it
	return dp[n] = fibTopDownDP(n-1, dp) + fibTopDownDP(n-2, dp);
}

// Bottom Up DP - Iterative Approach
// In Bottom Up DP, we start with small solutions and then
// use the small solutions to build larger solutions.
// Time Complexity: O(n)
// Space Complexity: O(n)

long long int fibBottomUpDP(int n) {
	int *arr = new int[n+1];
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i-1] + arr[i-2];
	}

	return arr[n];
}

// Time Complexity: O(n)
// Space Complexity: O(1)

long long int fibBottomUpDPOptimized(int n) {
	int prev = 0;
	int curr = 1;

	for (int i = 2; i <= n; i++) {
		int temp = prev + curr;
		prev = curr;
		curr = temp;
	}

	return curr;
}

int main() {
	int n = 7;

	cout << fib(n) << endl;

	int dp[100] = {0};
	cout << fibTopDownDP(n, dp) << endl;

	cout << fibBottomUpDP(n) << endl;

	cout << fibBottomUpDPOptimized(n) << endl;

	return 0;
}
