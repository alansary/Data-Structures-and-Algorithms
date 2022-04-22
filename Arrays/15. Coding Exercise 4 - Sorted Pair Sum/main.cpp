#include <iostream>
#include <vector>
using namespace std;

/*
 * Sorted Pair Sum
 * Given a sorted array and a number x, find a pair in array whose sum is closest to x.
 * Input Format
 * In the function an integer vector and number x is passed.
 * Output Format
 * Return a pair of integers.
 * Sample Input
 * {10, 22, 28, 29, 30, 40}, x = 54
 * Sample Output
 * 20 and 30
 */

// O(n^2)
pair<int, int> closestSumII(vector<int> arr, int x) {
	pair<int, int> integers;
	int sum, diff;
	int closest = INT_MAX;

	for (int i = 0; i < arr.size(); i++) {
		for (int j = i+1; j < arr.size(); j++) {
			sum = arr[i] + arr[j];
			diff = abs(sum - x);
			if (diff < closest) {
				closest = diff;
				integers.first = arr[i];
				integers.second = arr[j];
			}
		}
	}

	return integers;
}

// O(n)
pair<int, int> closestSum(vector<int> arr, int x) {
	pair<int, int> integers;
	int start = 0;
	int end = arr.size() - 1;
	int closest = INT_MAX;

	while (start < end) {
		if (abs(arr[start] + arr[end] - x) < closest) {
			closest = abs(arr[start] + arr[end] - x);
			integers.first = arr[start];
			integers.second = arr[end];
		}

		if (arr[start] + arr[end] > x) {
			end--;
		} else {
			start++;
		}
	}

	return integers;
}

int main() {
	vector<int> arr = {10, 22, 28, 29, 30, 40};
	int x = 54;
	pair<int, int> integers;

	integers = closestSum(arr, x);

	cout << integers.first << " and " << integers.second << endl;

	return 0;
}
