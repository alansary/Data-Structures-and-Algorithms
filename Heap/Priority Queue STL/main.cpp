#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Compare {
public:
	bool operator()(int a, int b) { // Overloading () operator
		return a > b;
	}
};

int main() {
	vector<int> v = {10, 15, 20, 13, 6, 90};

	priority_queue<int> max_heap;
	for (int e : v) {
		max_heap.push(e);
	}
	while (!max_heap.empty()) {
		cout << max_heap.top() << " ";
		max_heap.pop();
	}
	cout << endl;

	// greater<int> is an inbuilt comparator
	priority_queue<int, vector<int>, greater<int>> min_heap;
	for (int e : v) {
		min_heap.push(e);
	}
	while (!min_heap.empty()) {
		cout << min_heap.top() << " ";
		min_heap.pop();
	}
	cout << endl;

	priority_queue<int, vector<int>, Compare> heap;
	for (int e : v) {
		heap.push(e);
	}
	while (!heap.empty()) {
		cout << heap.top() << " ";
		heap.pop();
	}
	cout << endl;

	return 0;
}
