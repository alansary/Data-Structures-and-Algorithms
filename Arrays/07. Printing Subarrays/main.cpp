#include <iostream>
using namespace std;

// O(n^3)
// n^2 subarrays
void print_subarrays(int * arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = i; k <= j; k++) {
				cout << arr[k] << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr) / sizeof(int);

	for (int x : arr) {
		cout << x << " ";
	}
	cout << "\n\n";

	print_subarrays(arr, n);

	return 0;
}
