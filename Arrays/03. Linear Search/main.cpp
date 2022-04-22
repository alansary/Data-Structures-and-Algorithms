#include <iostream>
using namespace std;

// Brute Force - O(n)
int linear_search(int * arr, int n, int key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) return i;
	}
	return -1;
}

int main() {
	int arr[] = {1, 2, 0, 10, 11, 9, 8, 8, 7};
	int key = 9;

	int n = sizeof(arr) / sizeof(int);

	cout << linear_search(arr, n, key) << endl;

	return 0;
}
