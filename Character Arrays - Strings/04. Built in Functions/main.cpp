#include <iostream>
using namespace std;

// Built in Functions

int main() {
	char a[100] = "apple";
	char b[100];

	cout << strlen(a) << endl;

	strcpy(b, a); // copy in destination from source
	cout << b << endl;

	cout << strcmp(a, b) << endl; // returns 0 if match

	char www[] = "www.";
	char domain[] = "google.com";
	cout << strcat(www, domain) << endl;

	return 0;
}
