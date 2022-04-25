#include <iostream>
#include <vector>
using namespace std;

/*
 * Make Zeroes
 * Given a two-dimensional array, if any element within is zero,
 * make its whole row and column zero. For example, consider
 * the matrix below.
 *
 * 5	4	3	9
 * 2	0	7	6
 * 1	3	4	0
 * 9	8	3	4
 *
 * 5	0	3	0
 * 0	0	0	0
 * 0	0	0	0
 * 9	0	3	0
 *
 * Input Format
 * In the function a 2d vector is passed.
 * Output Format
 * Return the updated 2d vector.
 *
 * Sample Input
 * { {5, 4, 3, 9}, {2, 0, 7, 6}, {1, 3, 4, 0}, {9, 8, 3, 4} }
 *
 * Sample Output
 * { {5, 0, 3, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {9, 0, 3, 0} }
 */

vector<vector<int>> makeZeroes(vector<vector<int>> arr){
    // traverse the matrix and detect the ith and jth that contain zeros
	vector<pair<int, int>> pairs;
	for (int i = 0; i < arr.size(); i++) {
    	for (int j = 0; j < arr.size(); j++) {
    		if (!arr[i][j]) {
    			pairs.push_back({i, j});
    		}
    	}
    }

	// make pairs zeroes
	for (int k = 0; k < pairs.size(); k++) {
		for (int i = 0; i < arr.size(); i++) {
			arr[pairs[k].first][i] = 0;
		}
		for (int j = 0; j < arr.size(); j++) {
			arr[j][pairs[k].second] = 0;
		}
	}

	return arr;
}

int main() {
	vector<vector<int>> arr = {
			{5, 4, 3, 9},
			{2, 0, 7, 6},
			{1, 3, 4, 0},
			{9, 8, 3, 4}
	};
	vector<vector<int>> zeroes_arr;

	zeroes_arr = makeZeroes(arr);

	for (int i = 0; i < zeroes_arr.size(); i++) {
		for (int j = 0; j < zeroes_arr[0].size(); j++) {
			cout << zeroes_arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
