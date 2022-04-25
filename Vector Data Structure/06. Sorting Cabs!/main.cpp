#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Sorting Cabs!
 * Given a vector of pairs representing coordinates x and y
 * of different cabs on a X-Y plane. Sort them according to
 * their distance from the origin in the non-decreasing order
 * i.e. the cab with shortest distance from the origin will be
 * at first.
 * Input Format
 * In the function an integer vector of pairs is passed.
 * Output Format
 * Return an integer vector of pairs in sorted order.
 *
 * Sample Input
 * { (2, 3), (1, 2), (3, 4), (2, 4), (1, 4) }
 *
 * Sample Output
 * { (1, 2), (2, 3), (1, 4), (2, 4), (3, 4) }
 */

bool compare(pair<int, int> p1, pair<int, int> p2) {
	return sqrt(pow(p1.first, 2) + pow(p1.second, 2)) < sqrt(pow(p2.first, 2) + pow(p2.second, 2));
}

vector<pair<int, int>> sortCabs(vector<pair<int, int>> v) {
	sort(v.begin(), v.end(), compare);

	return v;
}

int main() {
	vector<pair<int, int>> v = {
			{2, 3}, {1, 2}, {3, 4}, {2, 4}, {1, 4}
	};
	vector<pair<int, int>> v_sorted;

	v_sorted = sortCabs(v);

	for (pair p : v_sorted) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	return 0;
}
