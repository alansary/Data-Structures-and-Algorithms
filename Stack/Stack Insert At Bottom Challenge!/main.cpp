#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int data) {
//	stack<int> temp;
//	while (!s.empty()) {
//		temp.push(s.top());
//		s.pop();
//	}
//
//	s.push(data);
//
//	while (!temp.empty()) {
//		s.push(temp.top());
//		temp.pop();
//	}

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

int main() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);

	insertAtBottom(s, 100);

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}
