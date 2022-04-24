#include <iostream>
using namespace std;

/*
 * Spiral Print
 * Write a function that takes in n x m 2D Array, and prints all
 * array elements in a spiral order. Start from top left corner
 * goes to right, proceeds in a spiral pattern until every element
 * is visited.
 *
 * Input
 * 1 2 3 4
 * 5 6 7 8
 * 9 10 11 12
 * 13 14 15 16
 *
 * Output
 * 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
 */

void spiralPrint(int arr[][4], int n, int m) {
	int row_start = 0;
	int row_end = n - 1;
	int column_start = 0;
	int column_end = m - 1;

	while (row_start <= row_end || column_start <= column_end) {
		// top row
		for (int j = column_start; j <= column_end; j++) {
			cout << arr[row_start][j] << " ";
		}
		row_start++;
		// right column
		for (int i = row_start; i <= row_end; i++) {
			cout << arr[i][column_end] << " ";
		}
		column_end--;
		// bottom row
		for (int j = column_end; j >= column_start; j--) {
			cout << arr[row_end][j] << " ";
		}
		row_end--;
		// left column
		for (int i = row_end; i >= row_start; i--) {
			cout << arr[i][column_start] << " ";
		}
		column_start++;
	}
	cout << endl;
}

int main() {
	int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	spiralPrint(arr, 4, 4);

	return 0;
}
