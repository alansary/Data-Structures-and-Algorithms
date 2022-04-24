#include <iostream>
#include <vector>
using namespace std;

/*
 * Pascal's Triangle
 * Pascal's triangle is a triangular array of the binomial
 * coefficients. Write a function that takes an integer value
 * n as input and returns 2D array with first n lines of the
 * Pascal's triangle.
 *
 * Following are the first 5 rows of Pascal's Triangle.
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 * 1 4 6 4 1
 *
 * Input Format
 * In the function an integer N is passed.
 * Output Format
 * Return the output as vector of vectors.
 *
 * nth row formula: nC0, nC1, nC2, ..., nCn where nCr = n! / ((n - r)!r!)
 * Example: 4th row
 * 	4C0 = 4! / (4! * 0!) = 1
 * 	4C1 = 4! / (3! * 1!) = 4
 * 	4C2 = 4! / (2! * 2!) = 6
 * 	4C3 = 4! / (1! * 3!) = 4
 * 	4C4 = 4! / (0! * 4!) = 1
 *
 */

long long int factorial(int n) {
	if (n == 0) return 1;
	else return n * factorial(n-1);
}

int combination(int n, int r) {
	return factorial(n) / (factorial(n - r) * factorial(r));
}

vector<vector<int>> printPascal(int n)
{
    vector<vector<int>> pascal_triangle;

    for (int i = 0; i < n; i++) {
    	vector<int> row;
    	for (int j = 0; j <= i; j++) {
    		// calculate nCr
    		row.push_back(combination(i, j));
    	}
    	pascal_triangle.push_back(row);
    }

    return pascal_triangle;
}

int main() {
	int n;

	cin >> n;

	vector<vector<int>> pascal_triangle;

	pascal_triangle = printPascal(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << pascal_triangle[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}
