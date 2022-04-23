#include <iostream>
using namespace std;

/*
 * Problem: Read n strings and print the largest string. Each string can have up to 1000 characters.
 */

int main() {
	int n;
	cin >> n;
	cin.get(); // consume \n from the input buffer

	char largest_str[1000] = "";
	char sentence[1000];

	while (n--) {
		cin.getline(sentence, 1000);
		if (strlen(sentence) > strlen(largest_str)) {
			strcpy(largest_str, sentence);
		}
	}

	cout << largest_str << endl;

	return 0;
}
