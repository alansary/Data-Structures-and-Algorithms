#include <iostream>
using namespace std;

// Time Complexity - O(n)
// Space Complexity - O(n)
long long int factorial(long long int n) {
	if (n == 0) return 1; // base case

	return n * factorial(n - 1);
}

int main() {
	long long int n;
	cin >> n;

	cout << factorial(n) << endl;

	return 0;
}
