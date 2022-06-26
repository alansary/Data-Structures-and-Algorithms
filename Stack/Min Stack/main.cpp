#include <iostream>
#include <vector>
using namespace std;

// Min Stack

/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in
 * constant time.
 * Implement the MinStack class:
 * MinStack() initializes the stack object.
 * void push(int val) pushes the element val onto the stack.
 * void pop() removes the element on the top of the stack.
 * int top() gets the top element of the stack.
 * int getMin() retrieves the minimum element in the stack.
 *
 * Example 1:
 * Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * Output
 * [null,null,null,null,-3,null,0,-2]
 *
 * Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top();    // return 0
 * minStack.getMin(); // return -2
 *
 * Constraints:
 * -2^31 <= val <= 2^31 - 1
 * Methods pop, top and getMin operations will always be called on non-empty stacks.
 * At most 3 * 104 calls will be made to push, pop, top, and getMin.
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
private:
	vector<int> data;
	int min;
public:
    MinStack() {
    	min = INT_MAX;
    }

    void push(int val) {
    	data.push_back(val);

    	if (val < min) {
    		min = val;
    	}
    }

    void pop() {
    	if (data.back() == min) {
    		if (data.size() == 1) {
    			min = INT_MAX;
    		} else {
    			min = INT_MAX;

        		// Calculate new minimum
        		for (int i = 0; i < data.size() - 1; i++) {
        			if (data[i] < min) {
        				min = data[i];
        			}
        		}
    		}
    	}
    	data.pop_back();
    }

    int top() {
    	return data.back();
    }

    int getMin() {
    	return min;
    }
};

int main() {
	 MinStack *minStack = new MinStack();
	 minStack->push(-2);
	 minStack->push(0);
	 minStack->push(-3);
	 cout << minStack->getMin() << endl;
	 minStack->pop();
	 cout << minStack->top() << endl;
	 cout << minStack->getMin() << endl;

	return 0;
}
