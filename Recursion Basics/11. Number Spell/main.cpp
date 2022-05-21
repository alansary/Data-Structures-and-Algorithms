#include <iostream>
using namespace std;

/*
 * Number Spell
 * Given a number like 2021, convert into string like "two zero two one" recursively.
 */

string spells[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string number_spell(int n, string &s) {
	if (!n) return s;

	int digit = n % 10;
	s = spells[digit] + " " + s;

	return number_spell(n/10, s);
}

int main() {
	int n;
	cin >> n;
	string s;

	cout << number_spell(n, s) << endl;

	return 0;
}
