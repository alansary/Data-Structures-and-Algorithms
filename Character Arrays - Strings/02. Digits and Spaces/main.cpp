#include <iostream>
using namespace std;

// Given a sentence, count the number of alphabets, digits and spaces in the sentence

int main() {
	// store and then count or read one by one and then count

	char ch = cin.get();
	int alpha = 0, space = 0, digit = 0;

	while (ch != '\n') {
		if (ch >= '0' && ch <= '9') {
			digit++;
		} else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
			alpha++;
		} else if (ch == ' ' || ch == '\t') {
			space++;
		}
		ch = cin.get();
	}

	cout << "Alphabets: " << alpha << endl;
	cout << "Digits: " << digit << endl;
	cout << "Spaces: " << space << endl;

	return 0;
}
