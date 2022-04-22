#include <iostream>
using namespace std;

void printFunction1(int arr[]) {
	int size = sizeof(arr) / sizeof(int); // sizeof(int *) / sizeof(int)

	cout << "Print Function 1:\n";
	cout << "Size: " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void printFunction2(int * arr) {
	int size = sizeof(arr) / sizeof(int); // sizeof(int *) / sizeof(int)

	cout << "Print Function 2:\n";
	cout << "Size: " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void printFunction3(int * arr, int size) {
	cout << "Print Function 3:\n";
	cout << "Size: " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void updateFunction(int * arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] *= 2;
	}

	cout << "Update Function:\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int size = sizeof(arr) / sizeof(int);

	cout << "Main Function:\n";
	cout << "Size: " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	printFunction1(arr); // Passed by reference
	printFunction2(arr); // Passed by reference
	printFunction3(arr, size); // Passed by reference, pass size as well
	updateFunction(arr, size); // Passed by reference

	cout << "Main Function:\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
