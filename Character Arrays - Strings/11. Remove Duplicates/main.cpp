#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Remove Duplicates
 * Given a string S, the task is to remove all the duplicates in the given string in sorted order.
 * Input Format
 * In the function a string is passed.
 * Output Format
 * Return the updated string.
 *
 * Sample Input
 * string s = "geeksforgeeks"
 *
 * Sample Output
 * "efgkors"
 */
string removeDuplicate(string s){
    vector<int> freq(26, 0);
    string output;

    for (char c : s) {
    	if (c >= 'a' && c <= 'z') freq[(int)c - (int)'a']++;
    	else if (c >= 'A' && c <= 'Z') freq[(int)c - (int)'A']++;
    }

    for (int i = 0; i < 26; i++) {
    	if (freq[i] > 0) output += (char)(i + (int)'a');
    }

    return output;
}

int main() {
	string s = "geeksforgeeks";

	cout << removeDuplicate(s) << endl;

	return 0;
}
