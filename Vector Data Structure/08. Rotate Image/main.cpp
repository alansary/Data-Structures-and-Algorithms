#include <iostream>
#include <vector>
using namespace std;

/*
 * Rotate Image
 * You are given an n x n 2D matrix representing an image,
 * rotate the image by 90 degrees (clockwise).
 * You have to rotate the image in-place, which means you have
 * to modify the input 2D matrix directly. DO NOT allocate
 * another 2D matrix to do the rotation.
 *
 * Example:
 * 1	2	3		======>		7	4	1
 * 4	5	6		======>		8	5	2
 * 7	8	9		======>		9	6	3
 *
 * Sample Input
 * 	matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
 *
 * Sample Output
 * 	[[7, 4, 1], [8, 5, 2], [9, 6, 3]]
 *
 * Constraints:
 * 	matrix.length == n
 * 	matrix[i].length == n
 * 	1 <= n <= 20
 * 	-1000 <= matrix[i][j] <= 1000
 *
 * Idea:
 * Indices: (0, 0) & (0, 2), Swapping: (1, 3)
 * Indices: (0, 0) & (2, 2), Swapping: (3, 9)
 * Indices: (0, 0) & (2, 0), Swapping: (9, 7)
 * Indices: (0, 1) & (1, 2), Swapping: (2, 6)
 * Indices: (0, 1) & (2, 1), Swapping: (6, 8)
 * Indices: (0, 1) & (1, 0), Swapping: (8, 4)
 */

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int start = 0;
	int end = n -1;

	while (start < end) {
        for(int i = 0; i < (end-start); ++i) {
            swap(matrix[start][start+i], matrix[start+i][end]);
            swap(matrix[start][start+i], matrix[end][end-i]);
            swap(matrix[start][start+i], matrix[end-i][start]);
        }
        ++start;
        --end;
	}
}

int main() {
	vector<vector<int>> matrix = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
	};

	rotate(matrix);

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
