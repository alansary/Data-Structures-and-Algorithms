#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int arr[] = {10, 9, 8, 6, 5, 4, 3, 2, 11, 16, 8};
	int n = sizeof(arr) / sizeof(int);

	cout << "Original Array" << endl;
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	sort(arr, arr + n); // up to but not including the last element

	cout << "Sorted Array (Ascending)" << endl;
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	reverse(arr, arr + n);

	cout << "Reversed Array" << endl;
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	reverse(arr, arr + n);

	cout << "Reversed Array" << endl;
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	sort(arr, arr + n, compare);

	cout << "Sorted Array (Descending)" << endl;
	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
