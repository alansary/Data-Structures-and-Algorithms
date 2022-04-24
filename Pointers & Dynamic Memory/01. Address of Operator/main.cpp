#include <iostream>
using namespace std;

int main() {
	int x = 10;
	cout << x << endl;

	int * y = &x; // Address of x
	cout << y << endl;
	cout << *y << endl; // Dereferencing the pointer y

	return 0;
}
