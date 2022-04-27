#include <iostream>
using namespace std;

/*
 * Write a function to
 * - Clear Range of Bits
 */

void clearRangeOfBits(int &n, int i, int j) {
	int mask_1 = (~0) << (j + 1); // 11...1j00...0i00...0
	int mask_2 = (1 << i) - 1; // 00...0j00...0i11...1 = 2^i - 1
	int mask = mask_1 | mask_2; // 11...1j00...0i11...1

	n = n & mask;
}

int main() {
	int n, i, j;
 	cin >> n >> i >> j;

	clearRangeOfBits(n, i, j);

	cout << bitset<32>(n).to_string() << endl;

	return 0;
}
