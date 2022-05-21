#include <iostream>
using namespace std;

/*
 * Power Function
 * Write a function to find power of a number, both number & power are given as input!
 * Idea:
 * a^n = a * a^(n-1)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

long long int power(int a, int n) {
	if (n == 0) return 1;

	return a * power(a, n - 1);
}

// Time Complexity: O(logn)
// Space Complexity: O(logn)
// Example:
// 2^10
// (2^5)^2
// 2.(2^2)^2
// (2^1)^2
// 2.(2^0)^2
// 2^0 = 1
long long int optimized_power(int a, int n) {
	if (n == 0) return 1;

	long long int sub_problem = optimized_power(a, n/2);
	long long int sub_problem_sq = sub_problem * sub_problem;
	if (n & 1) return a * sub_problem_sq; // odd
	else return sub_problem_sq; //even
}

int main() {
	cout << power(2, 10) << endl;
	cout << optimized_power(2, 10) << endl;

	return 0;
}
