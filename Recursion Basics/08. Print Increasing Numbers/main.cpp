#include <iostream>
#include <vector>
using namespace std;

/*
 * Print Increasing Numbers
 * Given an integer N. Your task is to return an integer vector containing numbers from 1 to N
 * in increasing order.
 * Sample Input
 * 5
 * Sample Output
 * 1 2 3 4 5
 */

vector<int> helper(int N, vector<int> &output) {
	if (N == 0) return output;

	helper(N-1, output);
	output.push_back(N);

	return output;
}

vector<int> increasingNumbers(int N) {
	vector<int> output;
	output.clear();

	return helper(N, output);
}

int main() {
	vector<int> v = increasingNumbers(10);

	for (int e : v) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
