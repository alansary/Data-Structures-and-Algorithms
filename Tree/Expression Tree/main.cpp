#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
	string key;
	Node *left;
	Node *right;

	Node(string key) {
		this->key = key;
		left = right = nullptr;
	}
};

Node* buildLevelorder() {
	string n;
	getline(cin, n);

	if (n == "1-")
		return nullptr;

	queue<Node*> q;
	Node *root = new Node(n);
	q.push(root);

	string left, right;
	while (!q.empty()) {
		Node *front = q.front();
		q.pop();

		getline(cin, left);
		getline(cin, right);

		if (left != "-1") {
			front->left = new Node(left);
			q.push(front->left);
		}

		if (right != "-1") {
			front->right = new Node(right);
			q.push(front->right);
		}
	}

	return root;
}

void traverseLevelorder(Node *root) {
	if (!root)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			Node *front = q.front();
			q.pop();

			cout << front->key << " ";
			if (front->left)
				q.push(front->left);
			if (front->right)
				q.push(front->right);
		}

		cout << endl;
	}

	return;
}

/*
 * Expression Tree
 *
 * Given a full binary expression tree consisting of basic binary operators (+,-,*,/) and
 * some integers in the form of string, your task is to evaluate the expression tree.
 *
 * Note: All the nodes' data are in the form of string.
 *
 * Input Format: In the function a pointer to the root node of the binary tree is passed.
 * Output Format: Return an integer representing the final value of the expression.
 *
 * Sample Input: + 3 * -1 -1 + 2 5 9 -1 -1 -1 -1 -1 -1
 * 							+
 * 						   /  \
 * 						  3    *
 * 						      /  \
 * 						     +    2
 * 						    / \
 * 						   5   9
 * Sample Output: 31
 *
 * Explanation: (((5 + 9) * 2) + 3) = 31
 */

int evalTree(Node* root){
	if (root->key == "+") {
		return evalTree(root->left) + evalTree(root->right);
	} else if (root->key == "*") {
		return evalTree(root->left) * evalTree(root->right);
	} else if (root->key == "/") {
		return evalTree(root->left) / evalTree(root->right);
	} else if (root->key == "-") {
		return evalTree(root->left) - evalTree(root->right);
	} else {
		return stoi(root->key);
	}
}

int main() {
	Node *t1 = buildLevelorder();
	traverseLevelorder(t1);
	cout << evalTree(t1) << endl;

	return 0;
}
