#include <iostream>
using namespace std;

/*
 * Replace Bits in N by M
 * You are given two 32-bit numbers, N and M, and two bit
 * positions i and j. Write a method to set all bits between
 * i and j in N equal to M.
 *
 * Example:
 * N = 10000000000
 * M = 10101
 * i = 2, j = 6
 * Output: 10001010100
 */

void replaceBits(int &n, int &m, int i, int j) {
	// clear bits from i to j in n
	int a = (~0) << (j + 1);
	int b = (1 << i) - 1;
	int mask = a | b;
	n = n & mask;

	// shift m to the left i times
	m = m << i;

	// OR with m
	n = n | m;
}

int main() {
	int n = 1024; // 10000000000
	int m = 21; // 10101
	int i = 2;
	int j = 6;

	replaceBits(n, m, i, j);

	cout << bitset<32>(n).to_string() << endl;

	return 0;
}
