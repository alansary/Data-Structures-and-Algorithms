#include <vector>
using namespace std;

template<typename T>
class Stack {
private:
	int head;
	vector<T> stack;
public:
	void push(T data) {
		stack.push_back(data);
	}

	void pop() {
		stack.pop_back();
	}

	T top() {
		return stack[stack.size()-1];
	}

	bool is_empty() {
		return stack.size() == 0;
	}
};
