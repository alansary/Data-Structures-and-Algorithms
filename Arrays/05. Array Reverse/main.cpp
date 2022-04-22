#include <iostream>
using namespace std;

void reverse_array_version_2(int * arr, int n) {
	int end = n - 1;

	for (int i = 0; i < n/2; i++) {
		swap(arr[i], arr[end-i]);
	}
}

// O(n)
void reverse_array(int * arr, int n) {
	int start = 0;
	int end = n - 1;

	while (start < end) {
		swap(arr[start], arr[end]);
		start += 1;
		end -= 1;
	}
}

int main() {
	int arr[] = {10, 20, 30, 45, 60, 80, 90};
	int n = sizeof(arr) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	reverse_array(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
