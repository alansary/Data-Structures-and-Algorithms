#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * String Compression
 * Given an array of characters chars, compress it using the following algorithm:
 * Begin with an empty string s. For each group of consecutive repeating characters in chars:
 * 	If the group's length is 1, append the character to s.
 * 	Otherwise, append the character followed by the group's length.
 * The compressed string s should not be returned separately, but instead be stored in the input character array chars. Note that group
 * lengths that are 10 or longer will be split into multiple characters in chars.
 * After you are done modifying the input array, return the new length of the array.
 * You must write an algorithm that uses only constant extra space.
 * Input Format
 * In the function a vector of characters is passed.
 * Output Format
 * Return the updated vector
 *
 * Example 1:
 * Input: chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'}
 * Output: Return 6, and the first 6 characters of the input array should be:
 * {'a', '2', 'b', '2', 'c', '3'}
 * Explanation: The groups are "aa", "bb", and "ccc". This compress to "a2b2c3".
 *
 * Example 2:
 * Input: chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}
 * Output: Return 4, and the first 4 characters of the input array should be: {'a', 'b', '1', '2'}
 * Explanation: The groups are "a" and "bbbbbbbbbbbb". This compress to "ab12"
 */
int compress(vector<char>& chars) {
	int n = chars.size();
	vector<char> output;

	for (int i = 0; i < n; i++) {
    	char c = chars[i];
    	int cnt = 1;
    	while (i+1 < n && chars[i+1] == c) {
    		cnt++;
    		i++;
    	}
    	if (cnt == 1) {
    		output.push_back(c);
    	} else if (cnt < 10) {
    		output.push_back(c);
    		output.push_back((char)cnt);
    	} else if (cnt >= 10) {
    		output.push_back(c);
    		string cnt_string = to_string(cnt);
    		for (char c : cnt_string) {
    			output.push_back(c);
    		}
    	}
    }

	return output.size();
}

int main() {
//	vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
	vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};

	cout << compress(chars);

	return 0;
}
