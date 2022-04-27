#include <iostream>
using namespace std;

/*
 * Idea:
 * 16 = 10000
 * 15 = 16 - 1 = 01111
 * 16 & 15 = 00000
 */

bool twoPower(int n) {
	return !(n & (n-1)) ? true : false;
}

int main() {
	for (int i = 0; i <= 32; i++) {
		twoPower(i) ? cout << i << " is a power of 2" << endl : cout << i << endl;
	}

	return 0;
}
