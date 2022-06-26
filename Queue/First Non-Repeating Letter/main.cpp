#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * First Non-Repeating Letter
 *
 * Given a string, your task is to find first non repeating character at each index
 * otherwise return 0.
 *
 * Input Format: In the function a vector of character that contains only lower case
 * characters is passed.
 * Output Format: Return a vector of character.
 *
 * Sample Input:  a b c b b a c d d
 * Sample Output: a a a a a c 0 d 0
 *
 * Sample Input:  a a b c
 * Sample Output: a 0 b b
 */

const int MAX_CHAR = 26;

vector<char> firstnonrepeating(vector<char> str) {
	vector<char> result;
	int counts[MAX_CHAR] = {0};
	queue<int> q;

	// Looping through characters
	for (int i = 0; i < str.size(); i++) {
		// Push char to queue
		q.push(str[i]);
		// Increase char count
		counts[str[i] - 'a']++;

		while (!q.empty()) {
			if (counts[q.front() - 'a'] > 1)
				q.pop();
			else {
				result.push_back(q.front());
				break;
			}
		}

		if (q.empty())
			result.push_back('0');
	}

	return result;
}

int main() {
	vector<char> input = {'a', 'b', 'c', 'b', 'b', 'a', 'c', 'd', 'd'};
	vector<char> output = firstnonrepeating(input);

	for (char c : output) {
		cout << c << " ";
	}
	cout << endl;

	input = {'a', 'a', 'b', 'c'};
	output = firstnonrepeating(input);

	for (char c : output) {
		cout << c << " ";
	}
	cout << endl;

	input = {'a', 'a', 'a', 'c'};
	output = firstnonrepeating(input);

	for (char c : output) {
		cout << c << " ";
	}
	cout << endl;

	return 0;
}
