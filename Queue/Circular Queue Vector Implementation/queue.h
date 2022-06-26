#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
	vector<int> data;
	int front_ptr;
	int rear_ptr;
	int capacity;
	int s;
public:
	Queue(int size) {
		capacity = size;
		data.resize(capacity);
		front_ptr = rear_ptr = -1;
		s = 0;
	}

	void push(int n) {
		if (empty()) {
			front_ptr = 0;
		}

		rear_ptr = (rear_ptr+1) % capacity;
		data[rear_ptr] = n;
		s++;
	}

	void pop() {
		if (!empty()) {
			front_ptr = (front_ptr + 1) % capacity;
			s--;
		}
	}

	bool empty() const {
		return !s;
	}

	bool full() const {
		return (s == capacity);
	}

	int front() const {
		return data[front_ptr];
	}

	int back() const {
		return data[rear_ptr];
	}

	int size() const {
		return s;
	}

	void print() const {
		if (rear_ptr >= front_ptr) {
			int i = front_ptr;
			while (i <= rear_ptr && i < capacity) {
				cout << data[i++] << " -> ";
			}
		} else {
			int i = front_ptr;
			while (i < capacity) {
				cout << data[i++] << " -> ";
			}
			i = 0;
			while (i <= rear_ptr) {
				cout << data[i++] << " -> ";
			}
		}
		cout << endl;
	}
};

class Node {
private:
	int data;
	Node* next;
public:
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}

	friend class DynamicQueue;
};

class DynamicQueue {
private:
	Node* front_ptr;
	Node* rear_ptr;
	int s;
public:
	DynamicQueue() {
		front_ptr = rear_ptr = nullptr;
		s = 0;
	}

	void push(int n) {
		Node* node = new Node(n);
		if (empty()) {
			front_ptr = rear_ptr = node;
		} else {
			rear_ptr->next = node;
			rear_ptr = node;
		}

		s++;
	}

	void pop() {
		if (!empty()) {
			Node* temp = front_ptr;
			front_ptr = front_ptr->next;
			delete temp;
			s--;
		}
	}

	bool empty() const {
		return !s;
	}

	int front() const {
		return front_ptr->data;
	}

	int back() const {
		return rear_ptr->data;
	}

	int size() const {
		return s;
	}

	void print() const {
		Node* ptr = front_ptr;
		while (ptr) {
			cout << ptr->data << " -> ";
			ptr = ptr->next;
		}
		cout << endl;
	}
};
