#include <iostream>
using namespace std;

/*
 * Mango Trees
 * Rahul's father has left a farm organized as N x N grid.
 * Each square in the grid either has or does not have a mango
 * tree. He has to divide the farm with his three sisters as
 * follows: he will draw one horizontal line and one vertical line
 * to divide the field into four rectangles. His friends will choose
 * three of the four smaller fields and he gets the last one.
 * Goal: Max number of trees Rahul can get; that is, he needs to maximize his minimum.
 */

int mongoTrees(int farm_grid[][6], int n, int m) {
	// create auxiliary array of trees counts of a field - O(n^2)
	int aux[6][6];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) {
				// first block
				aux[i][j] = farm_grid[i][j];
			} else if (i == 0 && j != 0) {
				// first row
				aux[i][j] = aux[i][j-1] + farm_grid[i][j];
			} else if (i != 0 && j == 0) {
				// first column
				aux[i][j] = aux[i-1][j] + farm_grid[i][j];
			} else {
				// inner block
				aux[i][j] = aux[i-1][j] + aux[i][j-1] - aux[i-1][j-1] + farm_grid[i][j];
			}
		}
	}

	// check all possible i, j fields and find the minimum trees through the four fields
	int max_min_trees = 0;
	for (int i = 1; i < n-1; i++) {
		for (int j = 1; j < m-1; j++) {
			int f1_trees = aux[i-1][j-1];
			int f2_trees = aux[i-1][m-1] - f1_trees;
			int f3_trees = aux[n-1][j-1] - f1_trees;
			int f4_trees = aux[n-1][m-1] - f2_trees - f3_trees + f1_trees;

			// pick minimum field
			int min = INT_MAX;
			if (f1_trees < min) min = f1_trees;
			if (f2_trees < min) min = f2_trees;
			if (f3_trees < min) min = f3_trees;
			if (f4_trees < min) min = f4_trees;

			if (min > max_min_trees) max_min_trees = min;
		}
	}

	return max_min_trees;
}

int main() {
	int farm_grid[6][6] = {
			{0, 1, 1, 0, 0, 0},
			{1, 0, 0, 1, 1, 0},
			{0, 1, 0, 0, 0, 0},
			{0, 1, 1, 0, 0, 1},
			{1, 0, 0, 1, 1, 0},
			{0, 1, 0, 0, 0, 0}
	};
	int n = 6;
	int m = 6;

	cout << mongoTrees(farm_grid, n, m) << endl;

	return 0;
}
