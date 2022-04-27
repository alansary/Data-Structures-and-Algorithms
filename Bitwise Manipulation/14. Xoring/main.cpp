#include <iostream>
#include <vector>
using namespace std;

/*
 * Xoring
 * We are given an array containing n numbers. All the numbers are
 * present twice except for one number which is only present once.
 * Find the unique number without taking any extra spaces and in
 * linear time.
 *
 * Input Format
 * An integer vector is passed in the function
 *
 * Constraints
 * n < 10^5
 *
 * Output Format
 * Return a single integer containing the unique number
 *
 * Sample Input
 * { 1, 2, 3, 1, 4, 2, 3 }
 * Sample Output
 * 4
 * Explanation
 * 4 is present only once
 */

int xoring(vector<int> v)
{
	int unique = v[0];
	for (int i = 1; i < v.size(); i++) {
		unique = unique ^ v[i];
	}

    return unique;
}

int main() {
	vector<int> v { 1, 2, 3, 1, 4, 2, 3 };

	cout << xoring(v) << endl;

	return 0;
}
