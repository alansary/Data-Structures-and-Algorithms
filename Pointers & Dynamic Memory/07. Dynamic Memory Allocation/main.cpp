#include <iostream>
using namespace std;

int main() {
	// static memory allocation in function call stack
	int arr[10];

	// dynamic memory allocation in heap - array
	int n;
	cin >> n;
	int * dynamic_arr = new int[n];

	// update & get value
	dynamic_arr[2] = 100;
	cout << dynamic_arr[2] << endl;
	cout << *(dynamic_arr + 2) << endl;
	dynamic_arr[0] = 10;
	cout << dynamic_arr[0] << endl;
	cout << *dynamic_arr << endl;

	// delete
	delete [] dynamic_arr; // will free the heap but not the stack

	cout << dynamic_arr << endl; // we can still get the address

	// dynamic memory allocation in heap - integer
	int *x = new int;
	*x = 10;
	cout << *x << endl;

	delete x; // will free the heap but not the stack

	cout << x << endl; // we can still get the address
}
