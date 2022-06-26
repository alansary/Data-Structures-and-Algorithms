#include <iostream>
#include "hashtable.h"
using namespace std;

int main() {
	Hashtable<int> h;

	h.insert("Mohamed", 1);
	h.insert("Ahmed", 2);
	h.insert("Mahmoud", 3);
	h.insert("Hussain", 13);
	h.insert("Youssef", 14);
	h.insert("Ali", 4);
	h.print();

	int *value = h.search("Youssef");
	if (value) cout << "Youssef Found! " << *value << endl;
	else cout << "Youssef Not Found!" << endl;
	value = h.search("Joe");
	if (value) cout << "Joe Found! " << *value << endl;
	else cout << "Joe Not Found!" << endl;

	h.erase("Ali");
	h.erase("Mohamed");
	h.erase("Mahmoud");
	h.print();

	cout << h["Hussain"] << endl;
	h["Hussain"] += 10;
	cout << h["Hussain"] << endl;
	h["Hussain"] = 5;
	cout << h["Hussain"] << endl;
	h["Hady"] = 2;
	cout << h["Hady"] << endl;

	return 0;
}
