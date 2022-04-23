#include <iostream>
#include <string>
using namespace std;

/*
 * Run Length Encoding for String Compression
 * If compressed string is bigger than original, then return original string.
 * Input: aaabbccddee
 * Ouput: a3b2c2d2e2
 * Input: abcd
 * Ouput: abcd
 */
string compress(string chars) {
	int n = chars.length();
	string output;

	for (int i = 0; i < n; i++) {
    	char c = chars[i];
    	int cnt = 1;
    	while (i+1 < n && chars[i+1] == c) {
    		cnt++;
    		i++;
    	}
    	output += c;
    	if (cnt > 1)
    		output += to_string(cnt);
    }

	return output;
}

int main() {
	cout << compress("aaabbccddee") << endl;
	cout << compress("abcd") << endl;

	return 0;
}
