#include <iostream>
#include <vector>
using namespace std;

/*
 * All Occurrence!
 * You are given an integer of size N. Your aim is to find all the occurrences (indices) of a
 * given element.
 *
 * Input Format:
 * Vector v and integer k (to find) are passed as parameters.
 *
 * Output Format:
 * Return a vector of integers containing all the indices in sorted manner.
 *
 * Sample Input:
 * 3
 * 1 2 5 3 1 2 3 8 6 3 6 7 9
 * Sample Output:
 * 3 6 9
 */

void helper(int k, vector<int> v, int index, vector<int> &vec) {
	if (index == v.size()) return;

	if (v[index] == k) {
		vec.push_back(index);
	}

	helper(k, v, index + 1, vec);
}

vector<int> findAllOccurences(int k, vector<int> v) {
	vector<int> vec;
	vec.clear();
	helper(k, v, 0, vec);
	return vec;
}

int main() {
	int k = 3;
	vector<int> v {1, 2, 5, 3, 1, 2, 3, 8, 6, 3, 6, 7, 9};
	vector<int> output;

	output = findAllOccurences(k, v);

	for (int e : output) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
