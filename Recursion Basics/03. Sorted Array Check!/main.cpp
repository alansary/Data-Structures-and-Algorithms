#include <iostream>
using namespace std;

/*
 * Sorted Array Check!
 * Write a function to check if array is sorted!
 */

bool isSorted(int * arr, int n) {
	if (n == 0 || n == 1) return true;
	return arr[0] <= arr[1] && isSorted(arr+1, n-1);
}

int main() {
	int arr[] {1, 5, 7, 9, 11, 13};

	cout << isSorted(arr, sizeof(arr)/sizeof(int)) << endl;

	return 0;
}
