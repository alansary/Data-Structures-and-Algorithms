#include <iostream>
#include <vector>
using namespace std;

/*
 * Maximum Product
 *
 * Given an array of integers nums, you will choose two different indices i and j of that
 * array. Return the maximum value of (nums[i]-1) * (nums[j]-1).
 *
 * Input Format: Vector nums[] of integers passed in the function.
 * Output Format: Return a single integer as required.
 *
 * Constraints:
 * - 2 <= nums.length <= 500
 * - 1 <= nums[i] <= 10^3
 *
 * Sample Input: nums = {3, 4, 5, 2}
 * Sample Output: 12
 * Explanation: (nums[1] - 1) * (nums[2] - 1) = (4 - 1) * (5 - 1) = 12
 */

class Heap {
private:
	vector<int> heap;

	void heapify(int i) {
		int left = 2 * i;
		int right = 2 * i + 1;

		// Select maximum between node and children
		int max_index = i;
		if (left < heap.size() and heap[left] > heap[i])
			max_index = left;
		if (right < heap.size() and heap[right] > heap[i]) {
			if (max_index == i) {
				max_index = right;
			} else {
				if (heap[right] > heap[max_index]) {
					max_index = right;
				}
			}
		}


		if (max_index != i) {
			swap(heap[max_index], heap[i]);
			heapify(max_index);
		}
	}
public:
	Heap(int capacity) {
		heap.reserve(capacity + 1); // To account for first empty slot in array
		heap.push_back(-1);
	}

	void push(int e) {
		heap.push_back(e);

		// Maintain heap order property
		int child = heap.size() - 1;
		int parent = child / 2;
		while (child != 1 && heap[child] > heap[parent]) {
			swap(heap[child], heap[parent]);
			child = parent;
			parent = child / 2;
		}
	}

	void print() {
		for (int i = 1; i < heap.size(); i++) {
			cout << heap[i] << " ";
		}
		cout << endl;
	}

	int top() {
		return heap[1];
	}

	void pop() {
		// swap heap[1] and heap[heap.size()-1]
		swap(heap[1], heap[heap.size() - 1]);

		// remove heap.size()-1 from heap
		heap.pop_back();

		// Heapify to maintain the heap order property
		heapify(1);
	}
};

int maxProduct(vector<int>& nums) {
    // Insert elements into heap in O(n) time
	Heap h(nums.size());
	for (int i = 0; i < nums.size(); i++) {
		h.push(nums[i]);
	}

	// Get the maximum two elements
	int a = h.top();
	h.pop();
	int b = h.top();

	return (a - 1) * (b - 1);
}

int main() {
	vector<int> nums = {3, 4, 5, 2};
	cout << maxProduct(nums) << endl;

	return 0;
}
