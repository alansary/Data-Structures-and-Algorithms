#include <iostream>
using namespace std;

/*
 * Last Occurrence
 * Write a function to find the last occurrence of an element in an array!
 */

/*
 * base case: array is empty, return -1
 * recursive case:
 * {1, 2, 3, 4, 3, 2, 5}
 * check {2, 3, 4, 3, 2, 5}
 * check {3, 4, 3, 2, 5}
 * check {4, 3, 2, 5}
 * check {3, 2, 5}
 * check {2, 5}
 * check {5}
 * check {} return -1
 * check if return is -1, then element not found in the sub array, then check the first element
 * else element already found, then return found index + 1
 * 	if found and last = -1 return 0 else return last + 1
 * 	if not found return -1
 * check 5 == 3? return -1
 * check 2 == 3? return -1
 * check 3 == 3? return 0
 * return 0 + 1
 * return 1 + 1
 * return 2 + 1
 * return 3 + 1
 */

int last_occurrence(int * arr, int n, int key) {
	if (n == 0) return -1; // base case

	int sub_index = last_occurrence(arr+1, n-1, key);
	if (sub_index != -1) {
		return sub_index + 1;
	} else {
		if (arr[0] == key) {
			return 0;
		} else {
			return -1;
		}
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 3, 2, 5};

	cout << last_occurrence(arr, sizeof(arr) / sizeof(int), 3) << endl;

	return 0;
}
