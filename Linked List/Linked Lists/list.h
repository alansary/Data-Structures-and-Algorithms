class Node {
	int data;
	Node* next;
public:
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}

	~Node() {
		if (next) {
			delete next;
		}
	}

	Node* get_next() {
		return next;
	}

	int get_data() {
		return data;
	}

	friend class LinkedList;
};

class LinkedList {
	Node* head;
	Node* tail;
	int size;

	int search_helper(int data, Node* ptr) {
		// base case
		if (!ptr) {
			return -1;
		}

		if (ptr->data == data) {
			return 0;
		}

		// recursive call
		int index = search_helper(data, ptr->next);
		if (index == -1) {
			return -1;
		} else {
			return search_helper(data, ptr->next) + 1;
		}
	}
public:
	LinkedList() {
		head = tail = NULL;
		size = 0;
	}

	~LinkedList() {
		if (head) {
			delete head;
		}
	}

	Node* get_head() {
		return head;
	}

	void push_front(int data) {
		if (!head) {
			Node* n = new Node(data); // dynamically allocated in heap
			head = tail = n;
		} else {
			Node* n = new Node(data);
			n->next = head;
			head = n;
		}
		size++;
	}

	void push_back(int data) {
		if (!tail) {
			Node* n = new Node(data);
			head = tail = n;
		} else {
			Node* n = new Node(data);
			tail->next = n;
			tail = n;
		}
		size++;
	}

	void pop_front() {
		if (size) {
			if (head == tail) {
				delete head;
				head = tail = NULL;
			} else {
				Node* temp = head;
				head = head->next;
				temp->next = NULL;
				delete temp;
			}
			size--;
		}
	}

	void pop_back() {
		if (size) {
			if (head == tail) {
				delete tail;
				head = tail = NULL;
			} else {
				Node* ptr = head;
				while (ptr->next != tail) {
					ptr = ptr->next;
				}
				ptr->next = NULL;
				delete tail;
				tail = ptr;
			}
			size--;
		}
	}

	void remove(int index) {
		if (size) {
			if (!index) {
				pop_front();
			} else {
				Node* ptr = head;
				for (int i = 1; i < index; i++) {
					ptr = ptr->next;
				}
				Node* temp = ptr->next;
				ptr->next = temp->next;
				temp->next = NULL;
				delete temp;
				size--;
			}
		}
	}

	void insert(int index, int data) {
		if (index) {
			Node* ptr = head;
			for (int i = 1; i < index; i++) {
				ptr = ptr->next;
			}
			Node* n = new Node(data);
			n->next = ptr->next;
			ptr->next = n;
			size++;
		} else {
			push_front(data);
		}
	}

	int search(int data) {
		Node* ptr = head;
		int index = 0;
		while (ptr) {
			if (ptr->data == data) {
				return index;
			}
			ptr = ptr->next;
			index++;
		}
		return -1;
	}

	int recursive_search(int data) {
		return search_helper(data, head);
	}

	Node* delete_tail(Node * head){
	    if (!head) {
	        return NULL;
	    }

	    if (!head->next) {
	        // only one element exists
	        delete head;
	        head = NULL;
	        return head;
	    }

	    Node* ptr = head;
	    while (ptr->next->next) {
	        ptr = ptr->next;
	    }
	    Node* temp = ptr->next->next;
	    ptr->next = NULL;
	    delete temp;
	    return head;
	}

	void reverse() {
		Node* prev = NULL;
		Node* current = head;
		tail = head;
		while (current) {
			// save the next node
			Node* temp = current->next;
			// make the current node point to previous node
			current->next = prev;
			// move prev to current position
			prev = current;
			// move current to next position
			current = temp;
		}
		head = prev;
	}
};
