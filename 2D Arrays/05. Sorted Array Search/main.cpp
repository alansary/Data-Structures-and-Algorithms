#include <iostream>
using namespace std;

/*
 * Sorted Array Search - Binary Search - O(logn + logm)
 * Write a function that searches for an element in row wise
 * and column wise sorted 2D array.
 */
pair<int, int> search(int arr[][4], int n, int m, int key) {
	pair<int, int> indices;
	indices.first = -1;
	indices.second = -1;
	int row_start = 0;
	int row_end = n - 1;
	int col_start = 0;
	int col_end = m - 1;
	int mid_row;
	int mid_col;

	while (row_start <= row_end) {
		mid_row = (row_start + row_end) / 2;
		if (key >= arr[mid_row][0] && key <= arr[mid_row][col_end]) {
			break;
		} else if (key > arr[mid_row][col_end]) {
			// search the next rows
			row_start = mid_row + 1;
		} else if (key < arr[mid_row][col_start]) {
			// search the previous rows
			row_end = mid_row - 1;
		}
	}

	while (col_start <= col_end) {
		mid_col = (col_start + col_end) / 2;
		if (key == arr[mid_row][mid_col]) {
			indices.first = mid_row;
			indices.second = mid_col;
			break;
		} else if (key > arr[mid_row][mid_col]) {
			// search right columns
			col_start = mid_col + 1;
		} else if (key < arr[mid_row][mid_col]) {
			// search left columns
			col_end = mid_col - 1;
		}
	}

	return indices;
}

int main() {
//	int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	int arr[][4] = {
			{10, 20, 30, 40},
			{15, 25, 25, 45},
			{27, 29, 37, 48},
			{32, 33, 39, 50}
	};
	int n = 4;
	int m = 4;
//	int key = 10;
	int key = 25;
	pair<int, int> indices;

	indices = search(arr, n, m, key);
	cout << "(" << indices.first << ", " << indices.second << ")" << endl;

	return 0;
}
