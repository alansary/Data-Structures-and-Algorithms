#include <iostream>
using namespace std;

//int binary_search_recursive(int * arr, int start, int end, int key) {
//	int mid = (start + end) / 2;
//	if (start == end) {
//		if (key == arr[mid]) {
//			return mid; // FOUND
//		} else {
//			return -1; // NOT FOUND
//		}
//	} else {
//		if (key < arr[mid]) {
//			// Search left array
//			end = mid-1;
//			return binary_search_recursive(arr, start, end, key);
//		} else {
//			// Search right array
//			start = mid+1;
//			return binary_search_recursive(arr, start, end, key);
//		}
//	}
//}

//int binary_search_iterative(int * arr, int start, int end, int key) {
//	int mid;
//
//	while (start <= end) {
//		mid = (start + end) / 2;
//		if (key == arr[mid]) {
//			return mid;
//		} else if (key < arr[mid]) {
//			// Search left array
//			end = mid - 1;
//		} else {
//			// Search right array
//			start = mid + 1;
//		}
//	}
//
//	return -1;
//}

/*
 * Time Complexity: O(logn)
 * Iteration 0 - n/(2^0)
 * Iteration 1 - n/(2^1)
 * Iteration 2 - n/(2^2)
 * ...
 * Iteration k - n/(2^k) == 1
 * n = 2^k - taking log base 2 of both sides
 * logn = k
 * Search space is monotonic; that is, non-decreasing or non-increasing
 */
int binary_search(int * arr, int n, int key) {
	int start = 0;
	int end = n - 1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (key == arr[mid]) {
			return mid;
		} else if (key < arr[mid]) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return -1;
}

int main() {
	int arr[] = {1, 2, 10, 11, 19, 29, 30};
	int key;

	cin >> key;

	int n = sizeof(arr) / sizeof(int);
	int start = 0;
	int end = n - 1;
//
//	cout << binary_search_recursive(arr, start, end, key) << endl;
//	cout << binary_search_iterative(arr, start, end, key) << endl;
	cout << binary_search(arr, n, key) << endl;

	return 0;
}
