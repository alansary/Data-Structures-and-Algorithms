#include <iostream>
#include <stack>
using namespace std;

// Valid Parentheses

/*
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 *
 * Example 2:
 * Input: s = "()[]{}"
 * Output: true
 *
 * Example 3:
 * Input: s = "(]"
 * Output: false
 *
 * Constraints:
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 */

bool isValid(string s) {
	stack<char> st;

	for (char c : s) {
		switch (c) {
		case '(':
		case '[':
		case '{':
			st.push(c);
			break;
		case ')':
			if (st.empty()) {
				return false;
			} else {
				if (st.top() != '(') {
					return false;
				}
				st.pop();
			}
			break;
		case ']':
			if (st.empty()) {
				return false;
			} else {
				if (st.top() != '[') {
					return false;
				}
				st.pop();
			}
			break;
		case '}':
			if (st.empty()) {
				return false;
			} else {
				if (st.top() != '{') {
					return false;
				}
				st.pop();
			}
			break;
		}
	}

	if (!st.empty()) {
		return false;
	}

	return true;
}

int main() {
	string s = "()[]{}";
	cout << isValid(s) << endl;

	return 0;
}
