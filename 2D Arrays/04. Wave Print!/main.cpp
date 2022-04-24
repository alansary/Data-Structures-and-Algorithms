#include <iostream>
#include <vector>
using namespace std;

/*
 * Wave Print!
 * Given a matrix, print it in Reverse Wave Form.
 * Input Format
 * Given integer m (number of rows), integer n (number of columns) and 2d vector.
 * Output Format
 * Return a linear vector of integers in the required order.
 *
 * Examples:
 *
 * Input:
 * 1 2 3 4
 * 5 6 7 8
 * 9 10 11 12
 * 13 14 15 16
 * Output:
 * 4 8 12 16 15 11 7 3 2 6 10 14 13 9 5 1
 *
 * Input:
 * 1 9 4 10
 * 3 6 90 11
 * 2 30 85 72
 * 6 31 99 15
 * Output:
 * 10 11 72 15 99 85 90 4 9 6 30 31 6 2 3 1
 */

vector<int> WavePrint(int m, int n, vector<vector<int>> arr) {
	vector<int> output;
	bool top_to_right = true; // initially looping from top to right

	// looping through columns from right to left
	for (int col = m - 1; col >= 0; col--) {
		if (top_to_right) {
			for (int row = 0; row < n; row++) {
				output.push_back(arr[row][col]);
			}
			top_to_right = false;
		} else {
			for (int row = n - 1; row >= 0; row--) {
				output.push_back(arr[row][col]);
			}
			top_to_right = true;
		}
	}
	return output;
}

int main() {
	vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	vector<int> output;
	int n = 4;
	int m = 4;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	output = WavePrint(m, n, arr);

	for (int i = 0; i < n * m; i++) {
		cout << output[i] << " ";
	}
	cout << endl;

	return 0;
}
