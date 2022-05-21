#include <iostream>
using namespace std;

/*
 * Understanding Recursion Directions
 * Print numbers 1...N recursively in
 * 	Decreasing order
 * 	Increasing order
 */

void print_dec(int n) {
	if (n == 0) return; // base case

	cout << n << " ";
	print_dec(n-1);
}

void print_inc(int n) {
	if (n == 0) return; // base case

	print_inc(n-1);
	cout << n << " ";
}

int main() {
	int n;
	cin >> n;

	print_dec(n);
	cout << endl;
	print_inc(n);

	return 0;
}
