#include <iostream>
using namespace std;

// Time Complexity - O(2^n)
// Space Complexity - O(n)
long long int fibonacci(long long int n) {
	if (n == 0 || n == 1) return n; // base case
	else
		return fibonacci(n - 2) + fibonacci(n - 1); // recursive case
}

int main() {
	long long int n;
	cin >> n;

	cout << fibonacci(n) << endl;

	return 0;
}
