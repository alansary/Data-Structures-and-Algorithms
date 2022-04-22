#include <iostream>
#include <vector>
using namespace std;

/*
 * Lower Bound
 * Given an array of integers A (sorted) and an integer Val.
 * Implement a function that takes A and Val as input parameters and returns the lower bound of Val.
 * Note: If Val is not present in array, then lower bound of a given integer means integer which is just smaller than given integer.
 * Otherwise Val itself is the answer.
 * If Val is less than smallest element of array A then return '-1' in that case.
 * Example 1:
 * A = [-1, -1, 2, 3, 5]
 * Val = 4
 * Answer: 3
 * Since 3 is just smaller than 4 in the array.
 * Example 2:
 * A = [1, 2, 3, 4, 6]
 * Val = 4
 * Answer: 4
 * Since 4 is equal to 4.
 *
 */
int lowerBound(vector<int> A, int Val) {
	int start = 0;
	int end = A.size() - 1;
	int lower_bound = -1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (Val == A[mid]) {
			return Val;
		} else if (Val > A[mid]) {
			start = mid + 1;
			lower_bound = A[mid];
		} else {
			end = mid - 1;
		}
	}

	return lower_bound;
}

int main() {
	vector<int> A = {-1, -1, 2, 3, 5}; // 3
	vector<int> B = {1, 2, 3, 4, 6}; // 4
	vector<int> C = {5, 6, 7, 8, 8}; // -1
	int Val = 4;

	cout << lowerBound(A, Val) << endl;
	cout << lowerBound(B, Val) << endl;
	cout << lowerBound(C, Val) << endl;

	return 0;
}
