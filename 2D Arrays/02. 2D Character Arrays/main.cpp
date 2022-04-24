#include <iostream>
using namespace std;

// 2D Character Arrays

int main() {
	// numbers of rows is optional
	char numbers[][10] = {
			"One",
			"Two",
			"Three",
			"Four",
			"Five",
			{'s', 'i', 'x', '\0'},
			"Seven"
	};

	for (int i = 0; i < 7; i++) {
		cout << numbers[i] << endl;
	}

	return 0;
}
