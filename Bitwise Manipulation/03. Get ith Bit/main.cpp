#include <iostream>
using namespace std;

/*
 * Write a function to
 * - Get ith Bit
 */

int getIthBitRS(int n, int i) {
	// using right shift
	n = (n >> i);

	return n & 1;
}

int getIthBitLS(int n, int i) {
	// using left shift
	int mask = (1 << i);

	return (n & mask) ? 1 : 0;
}

int main() {
	int n;
	cin >> n;

	for (int i = 31; i >= 0; i--) {
		cout << getIthBitRS(n, i);
	}
	cout << endl;
	for (int i = 31; i >= 0; i--) {
		cout << getIthBitLS(n, i);
	}
	cout << endl;

	return 0;
}
