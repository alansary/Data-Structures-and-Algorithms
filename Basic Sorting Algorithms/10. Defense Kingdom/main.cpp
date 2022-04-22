#include <iostream>
#include <vector>
using namespace std;

/*
 * Defense Kingdom
 * Theodore implemented a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a
 * rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and
 * the same column. No two towers share a row or a column.
 *
 * The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has
 * penalty 12.
 *
 * Your task is to find the penalty of the give position.
 * Input Format
 * In the function a width and height of the kingdom and a vector of pairs representing positions of towers is passed.
 * Output Format
 * Return an integer representing the number of cells in the largest rectangle that is not defended by the towers.
 * Sample Input
 * 15 8
 * {{3, 8}, {11, 2}, {8, 6}}
 * Sample Output
 * 12
 */
int defkin(int W, int H, vector<pair<int, int>> position)
{
	int n = position.size();

    // construct x-coordinates array
	vector<int> x(n + 2);

	//construct y-coordinates array
	vector<int> y(n + 2);

	x[0] = 0;
	y[0] = 0;
	for (int i = 0; i < n; i++) {
		x[i+1] = position[i].first;
		y[i+1] = position[i].second;
	}
	x[n+1] = W + 1;
	y[n+1] = H + 1;

	// sort the coordinates arrays using counting sort
	vector<int> x_freq(W + 2, 0);
	vector<int> y_freq(H + 2, 0);

	for (int i = 0; i < n + 2; i++) {
		x_freq[x[i]] += 1;
		y_freq[y[i]] += 1;
	}

	int j;

	j = 0;
	for (int i = 0; i < W + 2; i++) {
		while (x_freq[i]) {
			x[j++] = i;
			x_freq[i]--;
		}
	}

	j = 0;
	for (int i = 0; i < H + 2; i++) {
		while (y_freq[i]) {
			y[j++] = i;
			y_freq[i]--;
		}
	}

	int max_x = INT_MIN;
	int diff_x;
	for (int i = 0; i < n + 1; i++) {
		diff_x = x[i+1] - x[i] - 1;
		if (diff_x > max_x) {
			max_x = diff_x;
		}
	}

	int max_y = INT_MIN;
	int diff_y;
	for (int i = 0; i < n + 1; i++) {
		diff_y = y[i+1] - y[i] - 1;
		if (diff_y > max_y) {
			max_y = diff_y;
		}
	}

	return max_x * max_y;
}

int main() {
	int W = 15, H = 8;
	vector<pair<int, int>> position = {{3, 8}, {11, 2}, {8, 6}};

	cout << defkin(W, H, position) << endl;

	return 0;
}
