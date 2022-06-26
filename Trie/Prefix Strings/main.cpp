#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * Prefix Strings
 *
 * Given vector of strings and a small string. You need to find all the strings in the
 * vector which has small string as a prefix. Return the vector of required strings in
 * a sorted manner.
 *
 * Example: vector<string> words = {"abc", "abd", "acde", "abe", "aeb", "abba"}
 * string small = "ab"
 *
 * vector<string> output = {"abba", "abc", "abd", "abe"}
 */

class Node {
private:
	char ch;
	bool is_terminal;
	unordered_map<char, Node*> children;

public:
	Node(char ch) {
		this->ch = ch;
		is_terminal = false;
	}

	friend class Trie;
};

class Trie {
private:
	Node* root;

	void traverseAllPaths(Node* root, string s, vector<string> &output) {
		if (root->is_terminal) {
			s += root->ch;
			output.push_back(s);

			return;
		}

		// Recursive call
		s.push_back(root->ch);
		for (pair<char, Node*> node : root->children) {
			traverseAllPaths(node.second, s, output);
		}

		// Backtrack
		s.pop_back();

		return;
	}
public:
	Trie() {
		root = new Node('\0');
	}

	void insert(string s) {
		Node* ptr = root;
		for (char ch : s) {
			if (!ptr->children.count(ch)) {
				Node* node = new Node(ch);
				ptr->children[ch] = node;
			}

			ptr = ptr->children[ch];
		}

		ptr->is_terminal = true;
	}

	vector<string> havePrefix(string small) {
		vector<string> output;
		Node* ptr = root;

		for (char ch : small) {
			if (!ptr->children.count(ch)) {
				return output; // No matches exist
			}

			ptr = ptr->children[ch];
		}

		// ptr points to the node that has the last character in small
		if (ptr->is_terminal) output.push_back(small);

		string s;
		for (int i = 0; i < small.size() - 1; i++) s.push_back(small[i]);

		traverseAllPaths(ptr, s, output);

		sort(output.begin(), output.end());

		return output;
	}
};

vector<string> findPrefixStrings(vector<string> words, string prefix) {
	Trie t;
	for (string word : words) {
		t.insert(word);
	}

	return t.havePrefix(prefix);
}

int main() {
	vector<string> words = {"abc", "abd", "acde", "abe", "aeb", "abba"};
	string prefix = "ab";

	vector<string> output = findPrefixStrings(words, prefix);
	for (string s : output) {
		cout << s << endl;
	}


	return 0;
}
