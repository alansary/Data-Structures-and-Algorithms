#include <iostream>
using namespace std;

/*
 * Sorted Array Search - Staircase Search - O(n + m)
 * Write a function that searches for an element in row wise
 * and column wise sorted 2D array.
 */
pair<int, int> staircaseSearch(int arr[][4], int n, int m, int key) {
	int row_start = 0;
	int row_end = n - 1;
	int col_start = 0;
	int col_end = m - 1;

	// if element is not present
	if (key < arr[row_start][col_start] || key > arr[row_end][col_end]) {
		return {-1, -1};
	}

	// staircase search - start from first row, last column
	while (row_start <= row_end && col_end >= col_start) {
		if (arr[row_start][col_end] == key) {
			return {row_start, col_end};
		} else if (arr[row_start][col_end] > key) {
			col_end--;
		} else {
			row_start++;
		}
	}

	return {-1, -1};
}

int main() {
//	int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	int arr[][4] = {
			{10, 20, 30, 40},
			{15, 25, 35, 45},
			{27, 29, 37, 48},
			{32, 33, 39, 50}
	};
	int n = 4;
	int m = 4;
//	int key = 10;
	int key = 35;
	pair<int, int> indices;

	indices = staircaseSearch(arr, n, m, key);
	cout << "(" << indices.first << ", " << indices.second << ")" << endl;

	return 0;
}
