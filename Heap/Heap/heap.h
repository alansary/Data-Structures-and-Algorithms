#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
	vector<int> heap;

	void heapify(int i) {
		int left = 2 * i;
		int right = 2 * i + 1;

		// Select minimum between node and children
		int min_index = i;
		if (left < heap.size() and heap[left] < heap[i])
			min_index = left;
		if (right < heap.size() and heap[right] < heap[i]) {
			if (min_index == i) {
				min_index = right;
			} else {
				if (heap[right] < heap[min_index]) {
					min_index = right;
				}
			}
		}


		if (min_index != i) {
			swap(heap[min_index], heap[i]);
			heapify(min_index);
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
		while (child != 1 && heap[child] < heap[parent]) {
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
