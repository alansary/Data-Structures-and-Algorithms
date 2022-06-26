#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
 * Next Greater Element
 *
 * Given an array, return the Next Greater Element for every element. The Next Greater Element for
 * an element x is the first greater element on the right side of x in the array. Element for which
 * no greater element exist, consider the next greater element as -1.
 *
 * Input Format: In the function an integer vector is passed.
 * Output Format: Return an integer vector containing the next greater element for each element.
 *
 * Sample Input: v = {4, 5, 2, 25, 23}
 * Sample Output: {5, 25, 25, -1, -1}
 */

vector<int> nextGreaterElement(vector<int> v){
	stack<int> s;
	vector<int> output;

	for (int i = 0; i < v.size(); i++) {
		while (!s.empty() && s.top() < v[i]) {
			// Next Greater Element found
			output.push_back(v[i]);
			s.pop();
		}
		s.push(v[i]);
	}

	while (!s.empty()) {
		output.push_back(-1);
		s.pop();
	}

	return output;
}


int main() {
	vector<int> v = {4, 5, 2, 25, 23};
	vector<int> output = nextGreaterElement(v);

	for (int e : output) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
