#include <iostream>
#include <vector>
using namespace std;

/*
 * Sorting Cartesian Points
 * Given co-ordinates of N points on X-Y axis, your task is to sort them in accordance to the x-coordinate. If the x-coordinates are same then
 * compare y-coordinates.
 * Input Format
 * In the function an integer vector of pairs is passed.
 * Output Format
 * Return the vector in sorted order.
 * Sample Input
 * { {3, 4}, {2, 3}, {3, 7}, {1, 5}, {3, 4} }
 * Sample Output
 * { {1, 5}, {2, 3}, {3, 4}, {3, 4}, {3, 7} }
 */
vector<pair<int, int>> sortCartesian(vector<pair<int, int>> v)
{
	// insertion sort
    int n = v.size();
	for (int i = 1; i < n; i++) {
		pair<int, int> current = v[i];
		int j = i  - 1;

		while (j >= 0 && ((v[j].first == current.first && v[j].second > current.second) || (v[j].first > current.first))) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = current;
	}

    return v;
}

void insertion_sort(int * arr, int n) {
	for (int i = 1; i < n; i++) {
		int current = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > current) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = current;
	}
}

int main() {
	vector<pair<int, int>> pairs = { {3, 4}, {2, 3}, {3, 7}, {1, 5}, {3, 4} };
	vector<pair<int, int>> sorted_pairs;

	cout << "{ ";
	for (pair<int, int> x : pairs) {
		cout << "{" << x.first << ", " << x.second << "}, ";
	}
	cout << "}" << endl;

	sorted_pairs = sortCartesian(pairs);

	cout << "{ ";
	for (pair<int, int> x : sorted_pairs) {
		cout << "{" << x.first << ", " << x.second << "}, ";
	}
	cout << "}" << endl;

	return 0;
}
