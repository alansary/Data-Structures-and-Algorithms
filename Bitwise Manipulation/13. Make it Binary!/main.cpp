#include <iostream>
using namespace std;

/*
 * Make it Binary!
 */

int makeItBinary(int n) {
	int ans = 0;
	int mul = 1;

	while (n) {
		ans += ((n & 1) * mul);
		n = n >> 1;
		mul *= 10;
	}

	return ans;
}

int main() {
	int n;
	cin >> n;

	cout << makeItBinary(n) << endl;

	return 0;
}
