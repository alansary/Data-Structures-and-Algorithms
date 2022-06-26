#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node* next;
public:
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}

	friend class Queue;
};

class Queue {
private:
	Node* front_ptr;
	Node* rear_ptr;
	int s;
public:
	Queue() {
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
