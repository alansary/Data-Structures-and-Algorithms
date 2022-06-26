#include <iostream>
#include <vector>
using namespace std;

/*
 * First Non-Repeating Letter
 *
 * Given a string, your task is to find first non repeating character at each index
 * otherwise return 0.
 *
 * Input Format: In the function a vector of character that contains only lower case
 * characters is passed.
 * Output Format: Return a vector of character.
 *
 * Sample Input:  a b c b b a c d d
 * Sample Output: a a a a a c 0 d 0
 *
 * Sample Input:  a a b c
 * Sample Output: a 0 b b
 */

class ListNode {
private:
	char data;
	ListNode *next;
	ListNode *prev;
public:
	ListNode(int data) {
		this->data = data;
		next = prev = nullptr;
	}

	friend class List;
};

class List {
private:
	ListNode* head;
	ListNode* tail;
	vector<ListNode*> pointers;
	vector<bool> is_repeating;
public:
	List() {
		head = tail = nullptr;
		pointers.resize(26, nullptr); // 26 Characters
		is_repeating.resize(26, false); // 26 Characters
	}

	void push_back(char c) {
		ListNode* n = new ListNode(c);
		pointers[c - 'a'] = n;
		if (!tail) {
			head = tail = n;
		} else {
			n->prev = tail;
			tail->next = n;
			tail = n;
		}
	}

	char first_non_repeating() const {
		return head ? head->data : '0'; // '0' if no non-repeating characters exist
	}

	void remove(char c) {
		ListNode* ptr = head;
		while (ptr->data != c) {
			ptr = ptr->next;
		}

		if (ptr->prev) {
			ptr->prev->next = ptr->next;
			if (ptr == tail)
				tail = ptr->prev;
		} else {
			if (ptr == tail)
				tail = nullptr;
		}
		if (ptr->next) {
			ptr->next->prev = ptr->prev;
			if (ptr == head)
				head = ptr->next;
		} else {
			if (ptr == head) {
				head = nullptr;
			}
		}

		pointers[c - 'a'] = nullptr;
		is_repeating[c - 'a'] = true;
		delete ptr;
	}

	int search(char c) {
		if (pointers[c - 'a']) {
			return c - 'a';
		} else {
			return -1;
		}
	}

	bool is_char_repeating(char c) {
		return is_repeating[c - 'a'];
	}
};

vector<char> firstnonrepeating(vector<char> str){
	vector<char> result;
	List s;

	// Looping through elements
	for (int i = 0; i < str.size(); i++) {
		// Check if character is not repeating
		if (!s.is_char_repeating(str[i])) {
			// Check if it exists in non repeating list
			if (s.search(str[i]) == -1) { // Doesn't exist, then add it
				s.push_back(str[i]);
			} else { // Exists before, then remove it
				s.remove(str[i]);
			}
		}
		result.push_back(s.first_non_repeating());
	}

	return result;
}

int main() {
	vector<char> input = {'a', 'b', 'c', 'b', 'b', 'a', 'c', 'd', 'd'};
	vector<char> output = firstnonrepeating(input);

	for (char c : output) {
		cout << c << " ";
	}
	cout << endl;

	input = {'a', 'a', 'b', 'c'};
	output = firstnonrepeating(input);

	for (char c : output) {
		cout << c << " ";
	}
	cout << endl;

	input = {'a', 'a', 'a', 'c'};
	output = firstnonrepeating(input);

	for (char c : output) {
		cout << c << " ";
	}
	cout << endl;

	return 0;
}
