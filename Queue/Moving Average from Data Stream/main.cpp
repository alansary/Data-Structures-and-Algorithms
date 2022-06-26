#include <iostream>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;

// Moving Average from Data Stream

/*
 * Given a stream of integers and a window size, calculate the moving average of all
 * integers in the sliding window.
 * Implement the MovingAverage class:
 * MovingAverage(int size) Initializes the object with the size of the window size.
 * double next(int val) Returns the moving average of the last size values of the stream.
 *
 * Example 1:
 * Input
 * ["MovingAverage", "next", "next", "next", "next"]
 * [[3], [1], [10], [3], [5]]
 * Output
 * [null, 1.0, 5.5, 4.66667, 6.0]
 *
 * Explanation
 * MovingAverage movingAverage = new MovingAverage(3);
 * movingAverage.next(1); // return 1.0 = 1 / 1
 * movingAverage.next(10); // return 5.5 = (1 + 10) / 2
 * movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
 * movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
 *
 * Constraints:
 * 1 <= size <= 1000
 * -10^5 <= val <= 10^5
 * At most 10^4 calls will be made to next.
 */

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

class MovingAverage {
private:
	queue<int> data;
	int size;

public:
    MovingAverage(int size) {
        this->size = size;
    }

    double next(int val) {
    	if (data.size() == size) {
    		data.pop(); // keep only last size elements in the queue
    	}

    	data.push(val);

    	// Calculate the moving average
    	queue<int> temp;
    	double sum = 0;
    	int cnt = 0;

    	while (!data.empty()) {
    		int front = data.front();
    		data.pop();
    		temp.push(front);
    		sum += front;
    		cnt++;
    	}

    	while (!temp.empty()) {
    		data.push(temp.front());
    		temp.pop();
    	}

    	return sum / cnt;
    }
};

int main() {
	 MovingAverage movingAverage(3);
	 cout << movingAverage.next(1) << endl; // return 1.0 = 1 / 1
	 cout << movingAverage.next(10) << endl; // return 5.5 = (1 + 10) / 2
	 cout << movingAverage.next(3) << endl; // return 4.66667 = (1 + 10 + 3) / 3
	 cout << movingAverage.next(5) << endl; // return 6.0 = (10 + 3 + 5) / 3

	return 0;
}
