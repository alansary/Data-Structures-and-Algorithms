#include <iostream>
#include "trie.h"
using namespace std;

int main() {
	Trie t;
	cout << t.search("Hello") << endl;
	t.insert("Hello");
	cout << t.search("Hello") << endl;

	string words[] = {"hello", "he", "apple", "aple", "news"};
	Trie trie;

	for (auto word : words)
		trie.insert(word);

	string key;
	cin >> key;
	cout << trie.search(key) << endl;

	return 0;
}
