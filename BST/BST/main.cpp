#include <iostream>
using namespace std;

/*
 * All nodes on the left have value <= root
 * All nodes on the right have value > root
 * Inorder traversal returns sorted list
 * Search complexity: log(n) (balanced tree) <= h <= n (skewed tree)
 */

class Node {
public:
	int key;
	Node* left;
	Node* right;

	Node(int key) {
		this->key = key;
		this->left = this->right = nullptr;
	}
};

Node* insert(Node* root, int key) {
	if (!root) {
		return new Node(key);
	}

	if (key <= root->key) {
		root->left = insert(root->left, key);
	} else {
		root->right = insert(root->right, key);
	}

	return root;
}

void inorderTraversal(Node *root) {
	if (!root) {
		return;
	}

	inorderTraversal(root->left);
	cout << root->key << " ";
	inorderTraversal(root->right);
}

bool search(Node *root, int key) {
	if (!root) {
		return false;
	}

	if (root->key == key) {
		return true;
	} else if (key < root->key) {
		return search(root->left, key);
	} else {
		return search(root->right, key);
	}
}

Node* remove(Node *root, int key) {
	if (!root) {
		return nullptr;
	}

	if (key < root->key) {
		// search left sub-tree
		root->left = remove(root->left, key);
	} else if (key > root->key) {
		// search right sub-tree
		root->right = remove(root->right, key);
	} else {
		// remove the node

		if (!root->left && !root->right) {
			// if no children
			delete root;
			root = nullptr;
		} else if (!root->left) {
			// right child exists
			Node* temp = root;
			root = root->right;
			delete temp;
		} else if (!root->right) {
			// left child exists
			Node* temp = root;
			root = root->left;
			delete temp;
		} else {
			// two children exist
			// get smallest value from right sub-tree
			Node* curr = root->right;
			while (curr->left) {
				curr = curr->left;
			}
			// set root value with smallest from right sub-tree
			root->key = curr->key; // smallest from right sub-tree
			// remove smallest from right sub-tree
			root->right = remove(root->right, curr->key);
		}
	}

	return root;
}

int main() {
	Node* root = nullptr;
	int arr[] = {7, 9, 8, 5, 8, 4, 2, 5, 3, 10, 12, 11, 1, -1};

	for (int e : arr) {
		root = insert(root, e);
	}

	inorderTraversal(root); // -1 1 2 3 4 5 5 7 8 8 9 10 11 12
	cout << endl;

	cout << search(root, 5) << endl;
	cout << search(root, 6) << endl;

	root = remove(root, 9);

	inorderTraversal(root); // -1 1 2 3 4 5 5 7 8 8 10 11 12
	cout << endl;

	return 0;
}
