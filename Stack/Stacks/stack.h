template<typename T>
class Node {
public:
	T data;
	Node<T> *next;
	Node(T data) {
		this->data = data;
		next = NULL;
	}
};

template<typename T>
class Stack {
	Node<T>* head;
public:
	Stack() {
		head = NULL;
	}

	void push(T data) {
		Node<T> *n = new Node<T>(data);
		n->next = head;
		head = n;
	}

	void pop() {
		Node<T> *temp = head;
		head = head->next;
		delete temp;
	}

	T top() {
		return head->data;
	}

	bool is_empty() {
		return head == NULL;
	}
};
