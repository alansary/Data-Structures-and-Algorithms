#include <iostream>
using namespace std;

/*
 * Count Bits
 * Write a function to count set bits in a number!
 */

int count_bits(int n) {
	int cnt = 0;
	while (n > 0) { // O(logn)
		cnt += (n & 1); // increment with last bit
		n = n >> 1;
	}

	return cnt;
}

// faster method
/*
 * Example 1:
 * 16 = 00010000
 * 15 = 00001111
 * 16 & 15 = 00000000
 *
 * Example 2:
 * n = 9 = 1001
 * 8 = 1000
 * 9 & 8 = 1000
 * n = 8 = 1000
 * 7 = 0111
 * 8 & 7 = 0000
 * ...
 */

int count_bits_hack(int n) {
	int cnt = 0;
	while (n > 0) {
		n = n & (n - 1); // this operation remove last set bit at each iteration
		cnt++;
	}

	return cnt;
}

int main() {
	int n;
	cin >> n;

	cout << count_bits(n) << endl;
	cout << count_bits_hack(n) << endl;

	return 0;
}
