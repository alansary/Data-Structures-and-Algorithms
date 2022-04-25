#include <iostream>
#include <vector>
using namespace std;

int main() {
	// each row can have different number of elements
	vector<vector<int>> arr = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9, 10},
			{11, 12}
	};

	arr[0][0] += 10;

	for (int i = 0; i < arr.size(); i++) {
		for (int x : arr[i]) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}
