#include <iostream>
#include "vector.h"
using namespace std;

int main() {
	Vector<int> v(2);
	int i;

	cout << "Initial size: " << v.size() << endl;
	cout << "Initial capacity: " << v.capacity() << endl;
	cout << "Empty? " << v.empty() << endl;

	cout << "Push element: " << endl;
	cin >> i;
	v.push_back(i);
	cout << "Vector size: " << v.size() << endl;
	cout << "Vector capacity: " << v.capacity() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;

	cout << "Push element: " << endl;
	cin >> i;
	v.push_back(i);
	cout << "Vector size: " << v.size() << endl;
	cout << "Vector capacity: " << v.capacity() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;

	cout << "Push element: " << endl;
	cin >> i;
	v.push_back(i);
	cout << "Vector size: " << v.size() << endl;
	cout << "Vector capacity: " << v.capacity() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << "Empty? " << v.empty() << endl;

	cout << endl;

	// char vector
	Vector<char> vc(2);

	cout << "Initial size: " << vc.size() << endl;
	cout << "Initial capacity: " << vc.capacity() << endl;
	cout << "Empty? " << vc.empty() << endl;

	cout << "Push element: " << endl;
	vc.push_back('a');
	cout << "Vector size: " << vc.size() << endl;
	cout << "Vector capacity: " << vc.capacity() << endl;
	for (int i = 0; i < vc.size(); i++) {
		cout << vc.at(i) << " ";
	}
	cout << endl;

	cout << "Push element: " << endl;
	vc.push_back('b');
	cout << "Vector size: " << vc.size() << endl;
	cout << "Vector capacity: " << vc.capacity() << endl;
	for (int i = 0; i < vc.size(); i++) {
		cout << vc.at(i) << " ";
	}
	cout << endl;

	cout << "Push element: " << endl;
	vc.push_back('c');
	cout << "Vector size: " << vc.size() << endl;
	cout << "Vector capacity: " << vc.capacity() << endl;
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << " ";
	}
	cout << endl;

	cout << "Front: " << vc.front() << endl;
	cout << "Back: " << vc.back() << endl;
	cout << "Empty? " << vc.empty() << endl;

	return 0;
}
