#include <iostream>
#include "list.h"
using namespace std;

int main() {
	LinkedList l;
	l.pop_back();
	l.pop_front();
	l.push_front(5);
	l.pop_front();
	l.push_back(2);
	l.push_front(4);
	l.push_back(3);
	l.push_front(3);
	l.pop_front();
	l.remove(0);
	l.insert(0, 10);
	l.insert(1, 5);
	l.insert(4, 7);
	l.insert(5, 8);
	l.insert(5, 9);
//	cout << l.deleteTail(l.get_head())->get_data() << endl;
	Node* head = l.get_head();
	while(head) {
		cout << head->get_data() << "->";
		head = head->get_next();
	}
	cout << endl;
	l.reverse();
	head = l.get_head();
	while(head) {
		cout << head->get_data() << "->";
		head = head->get_next();
	}
	cout << endl;
}
