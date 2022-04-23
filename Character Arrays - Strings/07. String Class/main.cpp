#include <iostream>
#include <string>
#include <vector>
using namespace std;

// String Class

int main() {
	char str1[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'};
	char str2[] = "hello world";
	string str3 = "hello world"; // dynamic array
	string str4("hello world");

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;

	// getline();
	string str5;
	getline(cin, str5, '\n');
	cout << str5 << endl;

	// iterate through string
	for (char s : str5) {
		cout << s << " ";
	}
	cout << endl;

	// vector of strings
	int n;
	cin >> n;
	cin.get(); // clear \n

	vector<string> vstr;
	string temp;
	while (n--) {
		getline(cin, temp);
		vstr.push_back(temp);
	}

	for (string s : vstr) {
		cout << s << endl;
	}

	return 0;
}
