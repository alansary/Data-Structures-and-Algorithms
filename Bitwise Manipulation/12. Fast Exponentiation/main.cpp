#include <iostream>
using namespace std;

/*
 * Fast Exponentiation
 *
 * Idea:
 * Let a = 3 and n = 5
 * a^n = 3^5 = 3^(101)
 * 101 === a^4 a^2 a^1
 * a^n = 3^5 = a^4 . a^1 = a^5 = 3^5
 */

int fast_exponentiation(int a, int n) {
	int ans = 1;

	while (n > 0) {
		int last_bit = (n & 1);
		n = n >> 1;

		if (last_bit) {
			ans *= a;
		}

		a = a * a; // a^4 a^2 a^1
	}

	return ans;
}

int main() {
	int a, n;
	cin >> a >> n;

	cout << fast_exponentiation(a, n) << endl;

	return 0;
}
