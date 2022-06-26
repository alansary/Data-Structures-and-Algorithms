#include <iostream>
using namespace std;

class Node {
public:
	int key;
	Node* left;
	Node* right;

	Node(int key) {
		this->key = key;
		left = right = NULL;
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

void inorderTraversal(Node* root) {
	if (!root) {
		return;
	}

	inorderTraversal(root->left);
	cout << root->key << " ";
	inorderTraversal(root->right);
}

bool search(Node* root, int key) {
	if (!root) return false;

	if (root->key == key) {
		return true;
	} else if (key < root->key) {
		return search(root->left, key);
	} else {
		return search(root->right, key);
	}
}

Node* remove(Node* root, int key) {
	if (!root) return NULL;

	if (key < root->key) {
		root->left = remove(root->left, key);
	} else if (key > root->key) {
		root->right = remove(root->right, key);
	} else {
		if (!root->left && !root->right) {
			delete root;
			root = nullptr;
		} else if (!root->right) {
			Node* temp = root;
			root = root->left;
			delete temp;
		} else if (!root->left) {
			Node* temp = root;
			root = root->right;
			delete temp;
		} else {
			// Get max left from right sub-tree
			Node* ptr = root->right;
			while (ptr->left) {
				ptr = ptr->left;
			}
			root->key = ptr->key;
			root->right = remove(root->right, ptr->key);
		}
	}

	return root;
}

// Print all the elements of BST which lie in the range k1 and k2
void printInRange(Node* root, int k1, int k2) {
	if (!root) return;

	if (root->key >= k1 && root->key <= k2) {
		printInRange(root->left, k1, k2);
		cout << root->key << " ";
		printInRange(root->right, k1, k2);
	} else if (root->key > k2) {
		printInRange(root->left, k1, k2);
	} else if (root->key < k1) {
		printInRange(root->right, k1, k2);
	}

	return;
}

int main() {
	Node* root = nullptr;
	int arr[] = {7, 9, 8, 5, 8, 4, 2, 5, 3, 10, 12, 11, 1, -1};

	for (int e : arr) {
		root = insert(root, e);
	}

	inorderTraversal(root); // -1 1 2 3 4 5 5 7 8 8 9 10 11 12
	cout <<endl;

	cout << search(root, 5) << endl;
	cout << search(root, 6) << endl;

	root = remove(root, 9);

	inorderTraversal(root); // -1 1 2 3 4 5 5 7 8 8 10 11 12
	cout << endl;

	printInRange(root, 3, 9);

	return 0;
}
