#include <iostream>
using namespace std;

// Introduction

// Passing the number of columns is mandatory, array passed by reference
void print(int grades[][100], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grades[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int grades[100][100];
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grades[i][j];
		}
	}

	print(grades, n, m);

	return 0;
}
