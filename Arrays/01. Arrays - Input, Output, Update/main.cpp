#include <iostream>
using namespace std;

int main() {
	// creation
	int marks[100] = {-1}; // initialization list set the 1st element to -1, remaining elements will be set to 0 by default
	int n_students;

	cout << "Enter the number of students: ";
	cin >> n_students;

	cout << "Enter the marks of each student:\n";
	for (int i = 1; i <= n_students; i++) {
		// input
		cin >> marks[i];

		// update
		marks[i] += 10; // 10 marks bonus for each student
	}

	for (int i = 1; i <= n_students; i++) {
		// output
		cout << marks[i] << " ";
	}
	cout << endl;

	return 0;
}
