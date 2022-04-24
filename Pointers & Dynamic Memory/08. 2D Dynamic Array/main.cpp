#include <iostream>
using namespace std;

// returns a pointer to an array of pointers
int ** create2DArray(int rows, int cols) {
	int ** arr = new int *[rows]; // dynamic array of pointers to integers

	// allocate memory for each row
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}

	// initialize the array with increasing list of numbers
	int val = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = val++;
		}
	}

	return arr;
}

int main() {
	int rows, cols;

	cin >> rows >> cols;

	int ** arr = create2DArray(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
