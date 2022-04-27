#include <iostream>
using namespace std;

/*
 * Write a function to
 * - Set ith Bit
 */

void setIthBit(int &n, int i) {
	int mask = 1 << i;
	n = n | mask;
}

int main() {
	int n, i;
	cin >> n >> i;

	setIthBit(n, i);

	cout << bitset<32>(n).to_string() << endl;

	return 0;
}
