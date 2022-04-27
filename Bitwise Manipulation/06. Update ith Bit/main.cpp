#include <iostream>
using namespace std;

/*
 * Write a function to
 * - Update ith Bit
 */

void updateIthBit(int &n, int i, int v) {
	if (v) { // set
		int mask = 1 << i;

		n = (n | mask);
	} else { // clear
		int mask = ~(1 << i);

		n = (n & mask);
	}
}

void updateIthBitMethod2(int &n, int i, int v) {
	// clear ith bit
	int mask = ~(1 << i);
	n = (n & mask);

	// bitwise OR with v shifted i times
	mask = (v << i);
	n = (n | mask);
}

int main() {
	int n, i, v;
	cin >> n >> i >> v;

//	updateIthBit(n, i, v);
	updateIthBitMethod2(n, i, v);

	cout << bitset<32>(n).to_string() << endl;

	return 0;
}
