#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int data) {
	// Recursive Solution
	if (s.empty()) {
		s.push(data);
		return;
	}

	int top = s.top();
	s.pop();
	insertAtBottom(s, data);
	s.push(top);
}

void reverse(stack<int> &s) {
	if (s.empty()) {
		return;
	}

	int data = s.top();
	s.pop();
	reverse(s);
	insertAtBottom(s, data);
}

int main() {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	reverse(s);

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}
