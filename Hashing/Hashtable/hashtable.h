#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node {
public:
	string key;
	T value;
	Node<T>* next;

	Node(string key, T value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}

	~Node() {
		if (next) {
			delete next;
		}
	}
};

template<typename T>
class Hashtable {
private:
	Node<T>** table;
	int s; // size
	int c; // capacity

	int hash(string key) {
		int idx = 0;
		int power = 1;
		int base = 29;

		for (auto ch : key) {
			idx = (idx + (ch * power)) % c;
			power = (power * base) % c;
		}

		return idx;
	}

	void rehash() {
		// Backup old table and its size
		Node<T>** old_table = table;
		int size = c;
		// Create new table with double capacity
		c = 2 * c + 1; // Should be prime instead, 1 to make it odd
		s = 0; // Reset the number of elements
		table = new Node<T>*[c];
		// Initialize new table
		for (int i = 0; i < c; i++) {
			table[i] = NULL;
		}

		// Looping through the old table values
		for (int i = 0; i < size; i++) {
			// Looping through linked list elements
			Node<T>* temp = old_table[i];
			while (temp) {
				string key = temp->key;
				T value = temp->value;

				// Insert key-value pair in the new table
				insert(key, value);

				// Move to the next element
				temp = temp->next;
			}

			if (old_table[i]) {
				delete old_table[i];
			}
		}

		// Delete the dynamic array
		delete [] old_table;
	}

public:
	Hashtable(int capacity = 7) {
		c = capacity;
		s = 0;
		table = new Node<T>*[c];

		for (int i = 0; i < c; i++) {
			table[i] = NULL;
		}
	}

	void insert(string key, T value) {
		// Hash the key
		int idx = hash(key);

		// Insert key-value pair in the hashtable
		Node<T>* n = new Node<T>(key, value);
		n->next = table[idx];
		table[idx] = n;

		// Increase the size by 1
		s++;

		// Rehashing if load factor exceeds pre-defined threshold
		float load_factor = s / float(c);
		if (load_factor > 0.7) {
			rehash();
		}
	}

	void print() {
		for (int i = 0; i < c; i++) {
			cout << "Bucket #" << i << ":\n";
			if (table[i]) {
				Node<T>* ptr = table[i];
				while (ptr) {
					cout << "{" << ptr->key << ": " << ptr->value << "} -> ";
					ptr = ptr->next;
				}
				cout << endl;
			}
		}
		cout << endl;
	}

	T* search(string key) {
		// Hash the key
		int idx = hash(key);

		// Search the linked list persist into idx in table
		Node<T>* ptr = table[idx];
		while (ptr) {
			if (ptr->key == key) return &ptr->value;
			ptr = ptr->next;
		}

		return NULL; // Not found
	}

	void erase(string key) {
		// Hash the key
		int idx = hash(key);

		// Search the linked list persist into idx in table
		if (table[idx]) {
			Node<T>* ptr = table[idx];
			if (ptr->key == key) { // First node
				table[idx] = ptr->next;
				ptr->next = NULL;
				delete ptr;
				s--;
			} else { // Subsequent node
				while (ptr->next && ptr->next->key != key) {
					ptr = ptr->next;
				}
				if (ptr->next) {
					Node<T>* temp = ptr->next;
					ptr->next = ptr->next->next;
					temp->next = NULL;
					delete temp;
					s--;
				}
			}
		}
	}

	// Return memory location by reference
	T& operator[](string key) {
		T* value = search(key); // Search for the key if it exists

		if (!value) { // Not found
			T object; // Garbage T value
			insert(key, object);
			value = search(key); // Get the location
		}

		return *value;
	}
};
