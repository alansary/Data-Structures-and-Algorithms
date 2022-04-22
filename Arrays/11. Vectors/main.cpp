#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> arr1; // 0 size
	cout << arr1.size() << endl;
	cout << arr1.capacity() << endl;

	vector<int> arr2 = {1, 2, 10, 12, 15}; // initialize with elements
	cout << arr2.size() << endl; // Number of elements
	cout << arr2.capacity() << endl; // Capacity of the vector

	// Print the elements
	for (int x : arr2) {
		cout << x << " ";
	}
	cout << endl;
	for (int i = 0; i < arr2.size(); i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	// push_back O(1)
	arr2.push_back(16);
	cout << arr2.size() << endl; // Size increased by 1
	cout << arr2.capacity() << endl; // Double the previous capacity

	// pop_back O(1)
	arr2.pop_back();
	cout << arr2.size() << endl; // Size decreased by 1
	cout << arr2.capacity() << endl; // Same as the previous capacity

	// insert O(n)
	arr2.insert(arr2.begin(), 0);
	for (int x : arr2) {
		cout << x << " ";
	}
	cout << endl;
	cout << arr2.size() << endl;
	cout << arr2.capacity() << endl;

	// erase O(n)
	arr2.erase(arr2.begin());
	for (int x : arr2) {
		cout << x << " ";
	}
	cout << endl;
	cout << arr2.size() << endl;
	cout << arr2.capacity() << endl;

	// Check is empty
	cout << arr2.empty() << endl;

	// Fill constructor
	vector<int> arr3(10, 7); // number of elements, initial value
	for (int x : arr3) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
