#include <iostream>
using namespace std;

/*
 * First Occurrence
 * Write a function to find the first occurrence of an element in an array!
 */

/*
 * base case: array is empty, return -1
 * recursive case:
 * {1, 2, 3, 4, 3, 2, 5}
 * array[0] == key, return 0
 * check {2, 3, 4, 3, 2, 5}, if -1 return -1, else return 1 + index
 */

int first_occurrence(int * arr, int n, int key) {
	if (n == 0) return -1; // base case

	if (arr[0] == key) return 0;
	int sub_index = first_occurrence(arr+1, n-1, key);
	if (sub_index != -1) return sub_index + 1;
	return -1;
}

int main() {
	int arr[] = {1, 2, 3, 4, 3, 2, 5};

	cout << first_occurrence(arr, sizeof(arr) / sizeof(int), 3) << endl;

	return 0;
}
