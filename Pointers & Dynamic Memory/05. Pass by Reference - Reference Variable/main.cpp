#include <iostream>
using namespace std;

// pass by value
void applyTax(int income) {
	float tax = 0.10;
	income = income * (1 - tax);
}

// pass by reference using reference variable
void applyTaxPassByRfeference(int &money) { // money is a reference variable for income
	float tax = 0.10;
	money = money * (1 - tax);
}

int main() {
	int income;

	cin >> income;

	applyTax(income);

	cout << income << endl;

	applyTaxPassByRfeference(income);

	cout << income << endl;

	return 0;
}
