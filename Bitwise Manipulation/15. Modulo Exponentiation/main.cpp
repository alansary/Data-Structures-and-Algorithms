#include <iostream>
using namespace std;

/*
 * Modulo Exponentiation
 * Given three numbers x, y and mod, compute x raised to power y
 * modulo mod i.e. (x^y)%mod
 *
 * Input Format
 * Three integers x, y and mod are passed.
 * Output Format
 * Return an integer
 *
 * Sample Input
 * x = 12, y = 25, mod = 10007
 * Sample Output
 * 9603
 */

int power(int x, int y, int mod)
{
	int res = 1;

	x = x % mod; // Update x if it is more than or equal to mod

	if (x == 0) return 0; // In case x is divisible by mod

	while (y) {
		if (y & 1) {
			res = (res * x) % mod;
		}

		y = y >> 1; // remove last bit

		x = (x * x) % mod;
	}
    return res;
}

int main() {
	int x = 12;
	int y = 25;
	int mod = 10007;

	cout << power(x, y, mod) << endl;

	return 0;
}
