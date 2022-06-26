#include <unordered_map>
using namespace std;

class Node {
public:
	char ch;
	unordered_map<char, Node*> children;
	bool is_terminal;

	Node(char ch) {
		this->ch = ch;
		this->is_terminal = false;
	}
};

class Trie {
private:
	Node* root;
public:
	Trie() {
		root = new Node('\0');
	}

	void insert(string s) {
		Node* ptr = root;
		for (char ch : s) {
			// Create the character node if not exists
			if (!ptr->children.count(ch)) {
				Node* node = new Node(ch);
				ptr->children[ch] = node;
			}

			ptr = ptr->children[ch];
		}

		ptr->is_terminal = true; // Last node is a terminal node
	}

	bool search(string s) {
		Node* ptr = root;
		for (char ch : s) {
			if (!ptr->children.count(ch)) {
				return false;
			}
			ptr = ptr->children[ch];
		}

		return ptr->is_terminal;
	}
};
