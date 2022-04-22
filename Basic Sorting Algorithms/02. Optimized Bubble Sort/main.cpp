#include <iostream>
#include <vector>
using namespace std;

/*
 * Optimized Bubble Sort
 * In simple bubble sort algorithm, the time complexity will remain O(n^2) every time, even if the given array is already sorted.
 * Your task is to optimize the bubble sort such that its best case time complexity becomes O(n).
 * Input Format
 * In the function an integer vector is passed.
 * Output Format
 * Return an integer vector in non decreasing order.
 * Sample Input
 * {1, 3, 5, 7, 9}
 * Sample Output
 * {1, 3, 5, 7, 9}
 * Explanation
 * Given vector is already sorted
 */
vector<int> optimizedBubbleSort(vector<int> arr) {
	int n = arr.size();
	bool swapped;
	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}

	return arr;
}

int main() {
	vector<int> arr = {5, 4, 2, 3, 1};
	vector<int> sorted_arr;

	sorted_arr = optimizedBubbleSort(arr);

	for (int x : sorted_arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
