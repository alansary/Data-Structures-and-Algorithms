#include <iostream>
#include <vector>
using namespace std;

/*
 * Sorting with Comparator
 * Given an integer vector and a bool variable flag, your task is to sort the vector in accordance to the boolean value. If the bool value passed
 * is true then sort it in non-decreasing order or vice versa.
 * You can use any sorting technique of your choice.
 * Input Format
 * In the function an integer vector and a boolean is passed.
 * Output Format
 * Return an integer vector.
 * Sample Input
 * {111, 33, 5, 7, 29}, flag = 1
 * Sample Output
 * {5, 7, 29, 33, 111}
 */
vector<int> sortingWithComparator(vector<int> a, bool flag){
    // bubble sort
	int n = a.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (flag) {
				if (a[j] > a[j+1]) {
					swap(a[j], a[j+1]);
				}
			} else {
				if (a[j] < a[j+1]) {
					swap(a[j], a[j+1]);
				}
			}

		}
	}

	return a;
}

int main() {
	vector<int> arr = {111, 33, 5, 7, 29};
	bool flag = 1;

	for (int x : arr) {
		cout << x << " ";
	}
	cout << endl;

	vector<int> sorted_arr;
	sorted_arr = sortingWithComparator(arr, flag);

	for (int x : sorted_arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
