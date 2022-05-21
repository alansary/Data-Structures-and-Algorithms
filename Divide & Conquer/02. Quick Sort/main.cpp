#include <iostream>
using namespace std;

/*
 * Quick Sort
 * Average Case Time Complexity: O(nlogn)
 * Worst Case Time Complexity: O(n^2)
 */

void quick_sort(int * arr, int start, int end) {
	if (start == end) return; // 1 element is sorted

	int i = start;
	for (int j = start; j < end; j++) {
		if (arr[j] < arr[end]) {
			swap(arr[i++], arr[j]);
		}
	}
	swap(arr[i], arr[end]); // place the pivot in the correct location

	int mid = (start + end) / 2;
	quick_sort(arr, start, mid);
	quick_sort(arr, mid+1, end);
}

int main() {
	int arr[] {1, 7, 3, 2, 5, 4, 6, 2};
	quick_sort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
