#include <iostream>
using namespace std;

/*
 * Write an expression to check if a number is odd or even!
 * Observation: odd numbers right most bit is always 1.
 */

int main() {
	// check if last bit is 1
	cout << bitset<32>(5) << "\n&\n" << bitset<32>(1) << "\n================================\n" << bitset<32>(5 & 1) << endl;

	int n;
	cin >> n;
	if (n & 1) {
		cout << "Odd" << endl;
	} else {
		cout << "Even" << endl;
	}

	return 0;
}
