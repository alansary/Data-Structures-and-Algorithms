#include <iostream>
#include <string>
using namespace std;

/*
 * Vowel Find
 * Given a string consisting of lowercase English alphabets, return a string containing all the vowels present in S in serial order.
 * Input Format
 * In the function a string S is passed.
 * Output Format
 * Return a string.
 *
 * Sample Input
 * S = "aeoibsddaeioudb"
 *
 * Sample Output
 * "aeoiaeiou"
 */
string vowel(string S){
	string output;

    for (char c : S) {
    	switch (c) {
    	case 'a':
    	case 'e':
    	case 'i':
    	case 'o':
    	case 'u':
    		output += c;
    		break;
    	}
    }

    return output;
}

int main() {
	string S = "aeoibsddaeioudb";

	cout << vowel(S) << endl;

	return 0;
}
