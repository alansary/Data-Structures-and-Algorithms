#include <iostream>
#include <vector>
using namespace std;

/*
 * K-Rotate
 * Given an integer vector and a value k, your task is to rotate the array k-times clockwise.
 * Input Format
 * In the function an integer vector and number k is passed.
 * Output Format
 * Return an integer vector.
 * Sample Input
 * {1, 3, 5, 7, 9}, x = 2
 * Sample Output
 * {7, 9, 1, 3, 5}
 * Explanation
 * After 1st rotation - {9, 1, 3, 5, 7}
 * After 2nd rotation - {7, 9, 1, 3, 5}
 */
// O(n)
vector<int> kRotate(vector<int> a, int k){
	k %= a.size();
	vector<int> rotated_arr;

	for (int i = a.size() - k; i < a.size(); i++) {
		rotated_arr.push_back(a[i]);
	}
	for (int i = 0; i < a.size() - k; i++) {
		rotated_arr.push_back(a[i]);
	}

	return rotated_arr;
}

int main() {
	vector<int> arr = {1, 3, 5, 7, 9};
	int x = 2;

	vector<int> rotated_arr;
	rotated_arr = kRotate(arr, x);

	for (auto x : rotated_arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
