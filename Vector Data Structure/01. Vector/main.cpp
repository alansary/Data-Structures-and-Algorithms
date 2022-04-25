#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> arr;

	cout << arr.capacity() << endl;
	arr.push_back(0);
	cout << arr.capacity() << endl;
	arr.push_back(1);
	cout << arr.capacity() << endl;
	arr.push_back(2);
	cout << arr.capacity() << endl;
	arr.push_back(3);
	cout << arr.capacity() << endl;
	arr.push_back(4);
	cout << arr.capacity() << endl;

	cout << arr.size() << " elements exist in the vector" << endl;

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// pop element
	arr.pop_back();

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Is vector empty? " << arr.empty() << endl;

	// insert element at a given index
	arr.insert(arr.begin() + 2, 10);

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// initialize a vector
	vector<int> x = {1, 2, 3, 4, 5};

	// fill constructor initialization
	vector<int> y(10, 0); // 10 elements initialized to zero

	return 0;
}
