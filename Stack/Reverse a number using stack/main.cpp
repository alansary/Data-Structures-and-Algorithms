#include <iostream>
#include <stack>
using namespace std;

int reverse(int n) {
	stack<int> s;
	while (n / 10) {
		s.push(n % 10);
		n /= 10;
	}
	s.push(n);

	int base = 1;
	int number = 0;
	while (!s.empty()) {
		number += s.top() * base;
		base *= 10;
		s.pop();
	}

	return number;
}

int main() {
	cout << reverse(123) << endl;
	return 0;
}
