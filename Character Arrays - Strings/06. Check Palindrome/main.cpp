#include <iostream>
using namespace std;

/*
 * Check Palindrome
 * Given a string, write a C function to check if it is a palindrome or not.
 * A string is said to be a palindrome if reverse of the string is the same as string.
 * For example, "abba" is palindrome, but "abbc" is not palindrome.
 * Input Format
 * In the function a string is passed.
 * Output Format
 * Return true if it is palindrome else false.
 * Sample Input
 * abcdcba
 * Sample Output
 * true
 */

bool isPalindrome(string str)
{
    int start = 0;
    int end = str.length() - 1;
    while (start < end) {
    	if (str[start++] != str[end--]) {
    		return false;
    	}
    }

    return true;
}

int main() {
	string sentence;

	cin >> sentence;

	cout << isPalindrome(sentence) << endl;

	return 0;
}
