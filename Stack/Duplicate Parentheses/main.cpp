#include <iostream>
#include <stack>
using namespace std;

/*
 * Duplicate Parentheses
 *
 * Given a balanced expression, find if it contains duplicate parenthesis or not. A set of
 * parenthesis are duplicate if the same subexpression is surrounded by multiple parenthesis.
 *
 * Input Format: In the function a balanced string str is passed.
 * Output Format: Return a true if it contains duplicates else return false.
 *
 * Sample Input: ((a+b)+((c+d)))
 * Sample Output; true
 *
 * Sample Input: (((a+(b)))+(c+d))
 * true
 *
 * Explanation: ((c+d)) in the first example and ((a+(b))) in the second example are surrounded
 * by two pairs of parenthesis.
 */

bool duplicateParentheses(string str) {
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			int pop_count = 0;

			while (!s.empty() && s.top() != '(') {
				pop_count++;
				s.pop();
			}

			if (!pop_count) { // () found
				return true;
			}

			s.pop();
		} else {
			s.push(str[i]);
		}
	}

	return false;
}

int main() {
	string str = "((a+b)+((c+d)))";
	cout << duplicateParentheses(str) << endl;

	return 0;
}
