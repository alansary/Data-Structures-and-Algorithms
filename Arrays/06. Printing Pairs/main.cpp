#include <iostream>
using namespace std;

// (n-1) + (n-2) + (n-3) + ... + 3 + 2 + 1 = n^2
// O(n^2)
void print_pairs(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
		}
		cout << endl;
	}
}

int main() {
	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr) / sizeof(int);

//	for (int i = 0; i < n; i++) {
//		cout << arr[i] << " ";
//	}
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl << endl;

	print_pairs(arr, n);

	return 0;
}
