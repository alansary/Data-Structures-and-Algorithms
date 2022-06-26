#include <iostream>
#include "heap.h"
using namespace std;

int main() {
	Heap h(10);

	h.push(20);
	h.print();
	h.push(50);
	h.print();
	h.push(60);
	h.print();
	h.push(80);
	h.print();
	h.push(90);
	h.print();
	h.push(100);
	h.print();
	cout << h.top() << endl;

	h.pop();
	h.print();
	cout << h.top() << endl;

	return 0;
}
