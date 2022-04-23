#include <iostream>
#include <cstring>
using namespace std;

// Character Arrays Introduction

int main() {
	// declaration & initialization
	char str1[100]; // declaration
	char str2[] = {'a', 'b', 'c'}; // wrong initialization
	char str3[] = {'a', 'b', 'c', '\0'}; // correct initialization - null character termination
	char str4[] = "abc";

	// strlen & sizeof
	cout << str4 << endl;
	cout << strlen(str4) << endl; // number of characters
	cout << sizeof(str4) << endl; // number of characters + null character

	// cin will stop at '\n' and the input buffer will still contain the rest of the input

	// cin.get()
	char sentence[100];
	char temp = cin.get();
	int len = 0;
	while (temp != '\n' && len < 99) {
		sentence[len++] = temp;
		temp = cin.get();
	}
	sentence[len] = '\0';
	cout << "Length: " << len << endl;
	cout << sentence << endl;

	// cin.getline()
	cin.getline(sentence, 100); // stopping character is \n by default
	cout << sentence << endl;
	cin.getline(sentence, 100, '#'); // change stopping character
	cout << sentence << endl;

	return 0;
}
