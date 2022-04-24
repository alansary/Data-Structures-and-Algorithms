#include <iostream>
using namespace std;

int main() {
	int x = 10; // variable x
	int *xptr = &x; // pointer to variable x

	cout << x << endl; // value of x
	cout << xptr << endl; // address of x
	cout << *xptr << endl; // value of x

	// NULL pointer
	int *p = 0;
	int *q = NULL;
	cout << p << endl;
	cout << q << endl;

	return 0;
}
