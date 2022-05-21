#include <iostream>
using namespace std;

/*
 * Rotated Search
 * Write a function that takes input a sorted array of distinct integers, which is rotated
 * about a pivot point and find the index of any given element.
 * Sample Input
 * {7, 9, 10, 1, 2, 3, 4, 5, 6}
 * element = 4
 * Sample Output
 * 6
 *
 * Observations:
 * arr[end] <= arr[start]
 * if arr[start] <= arr[mid], then mid lies in the left sorted part of the array
 * if arr[mid] <= arr[end], then mid lies in the right sorted part of the array
 */

int rotated_search(int *arr, int n, int key) {
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] == key) {
			return mid;
		}

		// mid lies in the left sorted part of the array
		if (arr[start] <= arr[mid]) {
			if (key >= arr[start] and key <= arr[mid]) {
				end = mid - 1; // search the left part of the array
			} else {
				start = mid + 1; // search the right part of the array
			}
		} else {
			// mid lies in the right sorted part of the array
			if (key >= arr[mid] and key <= arr[end]) {
				start = mid + 1; // search the right part of the array
			} else {
				end = mid - 1; // search the left part of the array
			}
		}
	}

	return -1;
}

int main() {
	int arr[] {7, 9, 10, 1, 2, 3, 4, 5, 6};
	int key = 4;
	cout << rotated_search(arr, sizeof(arr) / sizeof(int), key) << endl;


	return 0;
}
