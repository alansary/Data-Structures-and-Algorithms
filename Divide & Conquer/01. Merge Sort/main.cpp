#include <iostream>
using namespace std;

/*
 * Merge Sort
 * Time Complexity: O(nlogn)
 * Divide: 1 3 2 5 7 6 1 4 5
 * Divide: 1 3 2 5 7
 * Divide: 1 3 2
 * Divide: 1 3
 * Divide: 1
 * Divide: 3
 * Merge: 1 and 3
 * Divide: 2
 * Merge: 1 3 and 2
 * Divide: 5 7
 * Divide: 5
 * Divide: 7
 * Merge: 5 and 7
 * Merge: 1 2 3 and 5 7
 * Divide: 6 1 4 5
 * Divide: 6 1
 * Divide: 6
 * Divide: 1
 * Merge: 6 and 1
 * Divide: 4 5
 * Divide: 4
 * Divide: 5
 * Merge: 4 and 5
 * Merge: 1 6 and 4 5
 * Merge: 1 2 3 5 7 and 1 4 5 6
 * 1 1 2 3 4 5 5 6 7
 */

void merge(int * arr, int start, int end) {
	int right_index = start;
	int mid = (start + end) / 2;
	int left_index = mid + 1;

	int * temp = new int[end - start + 1];
	int temp_index = 0;

	// sort values in temp array
	while (right_index <= mid && left_index <= end) {
		if (arr[right_index] < arr[left_index]) temp[temp_index++] = arr[right_index++];
		else temp[temp_index++] = arr[left_index++];
	}
	while (right_index <= mid) temp[temp_index++] = arr[right_index++];
	while (left_index <= end) temp[temp_index++] = arr[left_index++];

	// move sorted values to original array
	temp_index = 0;
	for (int i = start; i <= end; i++) {
		arr[i] = temp[temp_index++];
	}
}

void merge_sort(int * arr, int start, int end) {
	// 1 element is sorted
	if (start == end) return;

	// divide
	int mid = (start + end) / 2;
	merge_sort(arr, start, mid); // left array
	merge_sort(arr, mid+1, end); // right array

	// merge sorted arrays
	merge(arr, start, end);
}

int main() {
	int arr[] {1, 3, 2, 5, 7, 6, 1, 4, 5};
	int start = 0;
	int end = sizeof(arr) / sizeof(int) - 1;

	merge_sort(arr, start, end);

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
