#include <iostream>
using namespace std;

/*
 * Earth Levels!
 * The Planet Earth is under a threat from the aliens of the outer space and your task is to
 * defeat an enemy who is N steps above you (assume yourself to be at ground level i.e. at the
 * 0th level). You can take jumps in power of 2. In order to defeat the enemy as quickly as
 * possible you have to reach the Nth step in minimum moves possible.
 *
 * Input Format
 * In the function an integer is passed.
 * Output Format
 * Return an integer representing minimum jumps.
 *
 * Sample Input
 * 7
 * Sample Output
 * 3
 * Explanation
 * 0 -> 4 -> 6 -> 7
 */

int earthLevelNaive(int k)
{
	int min_jumps = 0;
	int total = 0;

	while (total != k) {
		// detect max jump
		int max_jump = 1; // 2^0
		while (total + max_jump < k) {
			max_jump *= 2;
		}
		if (total + max_jump > k) {
			max_jump /= 2;
		}
		total += max_jump;
		min_jumps++;
	}

	return min_jumps;
}

int convertToBinary(int n) {
	int binary = 0;
	int pos = 1;

	while (n) {
		int reminder = n % 2;
		n /= 2;
		binary += (reminder * pos);
		pos *= 10;
	}

	return binary;
}

int earthLevel(int k) {
	int binary = convertToBinary(k);
	int min_jumps = 0;

	while (binary) {
		min_jumps = min_jumps + (binary % 2);
		binary /= 10;
	}

	return min_jumps;
}

int main() {
	cout << earthLevel(7) << endl;

	return 0;
}
