#include <iostream>
using namespace std;

// Address of Operator

int main() {
	// Integer
	int x = 10;
	cout << x << endl;

	// Pointer to an integer
	int *xptr = &x; // Address of x
	cout << xptr << endl;
	cout << *xptr << endl; // Dereferencing the pointer y
	cout << &xptr << endl; // Address of the pointer xptr

	// Pointer to a pointer
	int **xxptr = &xptr;
	cout << xxptr << endl;
	cout << *xxptr << endl;
	cout << **xxptr << endl;

	return 0;
}
