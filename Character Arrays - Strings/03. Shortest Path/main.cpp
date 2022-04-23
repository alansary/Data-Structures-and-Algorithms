#include <iostream>
using namespace std;

/*
 * Find Displacement: Given a long route containing
 * N, S, E, W directions, find the shortest path to
 * reach the location.
 *
 * Sample Input:
 * SNNNEWE
 *
 * Sample Output:
 * NNE
 */

/*
 * 			North
 * 	West			East
 * 			South
 */

int main() {
	int x = 0; int y = 0; // initial position (x, y) at origin

	char ch = cin.get();
	while (ch != '\n') {
		if (ch == 'W') x--;
		else if (ch == 'E') x++;
		else if (ch == 'N') y++;
		else if (ch == 'S') y--;

		ch = cin.get();
	}

	while (y < 0) {
		cout << 'S';
		y++;
	}
	while (y > 0) {
		cout << 'N';
		y--;
	}
	while (x < 0) {
		cout << 'W';
		x++;
	}
	while (x > 0) {
		cout << 'E';
		x--;
	}
	cout << endl;

	return 0;
}
