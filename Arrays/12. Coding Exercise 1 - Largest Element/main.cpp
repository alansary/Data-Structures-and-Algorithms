#include <iostream>
#include <vector>
using namespace std;

/*
 * Largest Element
 * Implement a function that takes array of integers as input and returns the largest element.
 * Sample Input
 * -3 4 1 2 3
 * -1 -2 -3 -3 8
 * Sample Output
 * 4
 * 8
 * Explanation: for test case one, 4 is the largest integer in the array.
 * Similarly for test case two, 8 is the largest integer in the array.
 */
int largestElement(vector<int> arr) {
	int largest_element = INT_MIN;

	for (int x : arr) {
		largest_element = max(largest_element, x);
	}

	return largest_element;
}

int main() {
//	vector<int> arr = {-3, 4, 1, 2, 3};
	vector<int> arr = {-1, -2, -3, -3, 8};

	cout << largestElement(arr);

	return 0;
}
