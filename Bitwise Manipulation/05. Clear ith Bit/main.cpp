#include <iostream>
#include <cmath>
using namespace std;

/*
 * Write a function to
 * - Clear ith Bit
 */

void clearIthBit(int &n, int i) {
	int mask = ~(1 << i);

	n = (n & mask);
}

int main() {
	int n, i;
	cin >> n >> i;

	clearIthBit(n, i);

	cout << bitset<32>(n).to_string() << endl;

	return 0;
}
