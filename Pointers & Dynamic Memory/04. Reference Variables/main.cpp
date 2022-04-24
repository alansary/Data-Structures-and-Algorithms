#include <iostream>
using namespace std;

int main() {
	int x = 10;

	// reference variable to x, x and y reference the same location in memory
	int &y = x;

	y++;
	cout << x << endl;
	cout << y << endl;

	return 0;
}
