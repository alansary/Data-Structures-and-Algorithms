#include <iostream>
using namespace std;

/*
 * Write a function to
 * - Clear Last i Bits
 */

void clearLastIBits(int &n, int i) {
	int mask = ~0; // all ones
	mask = mask << i; // i zeros on the right
	n = n & mask;
}

int main() {
	int n, i;
	cin >> n >> i;

	clearLastIBits(n, i);

	cout << bitset<32>(n).to_string() << endl;

	return 0;
}
