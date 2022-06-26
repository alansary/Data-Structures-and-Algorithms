#include <iostream>
#include <queue>
using namespace std;

// Implement a Stack class which uses 2 Queues internally as a data structure.

class Stack {
private:
	queue<int> q1, q2;
public:
	void push(int n) {
		if (q1.empty() && q2.empty()) {
			q1.push(n);
		} else if (!q1.empty()) {
			q1.push(n);
		} else if (!q2.empty()) {
			q2.push(n);
		}
	}

	void pop() {
		if (!q1.empty()) {
			// copy all elements from q1 to q2 except the last element
			int size = q1.size();
			for (int i = 0; i < size - 1; i++) {
				q2.push(q1.front());
				q1.pop();
			}
			// remove last element from q1
			q1.pop();
		} else if (!q2.empty()) {
			// copy all elements from q2 to q1 except the last element
			int size = q2.size();
			for (int i = 0; i < size - 1; i++) {
				q1.push(q2.front());
				q2.pop();
			}
			// remove last element from q2
			q2.pop();
		}
	}

	int top() {
		int t;
		if (!q1.empty()) {
			// move all elements from q1 to q2
			while (!q1.empty()) {
				t = q1.front();
				q2.push(t);
				q1.pop();
			}
		} else if (!q2.empty()) {
			// move all elements from q2 to q2
			while (!q2.empty()) {
				t = q2.front();
				q1.push(t);
				q2.pop();
			}
		} else {
			t = -1;
		}

		return t;
	}
};

int main() {
	Stack s;
	s.push(1);
	cout << s.top() << endl;
	s.push(2);
	cout << s.top() << endl;
	s.push(3);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.push(4);
	cout << s.top() << endl;

	return 0;
}
