#include <iostream>
#include <queue>
using namespace std;

/*
 * K-th Level
 *
 * Given a binary tree with N nodes. Your task is to print its Kth level.
 *
 * Input Format: In the function a pointer to the root node of the binary tree is passed.
 * Output Format: Return a vector containing nodes at Kth level.
 *
 * Sample Input: 60 50 80 -1 -1 10 -1 -1 30 40 -1 -1 -1
 * Sample Input (Level Order): 60 50 30 80 10 40 -1 -1 -1 -1 -1 -1 -1
 * 				60				-- Level 0
 * 			   /  \
 * 			  50  30			-- Level 1
 * 			 / \  /
 * 			80 10 40			-- Level 2
 * K = 1
 * Sample Output: 50 30
 *
 * Sample Input: 50 60 90 -1 -1 40 -1 -1 70 40 -1 -1 20 -1 -1
 * Sample Input: 50 60 70 90 40 40 20 -1 -1 -1 -1 -1 -1 -1 -1
 * 					  50			-- Level 0
 * 				   /      \
 * 				  60      70		-- Level 1
 * 				 /  \     / \
 * 				90  40   40 20		-- Level 2
 * K = 2
 * Sample Output: 90 40 40 20
 */

class Node {
public:
	int key;
	Node* left;
	Node* right;

	Node(int key) {
		this->key = key;
		left = right = nullptr;
	}
};

Node* buildTree() {
	int n;
	cin >> n;

	if (n == -1) return nullptr;

	Node* root = new Node(n);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void traverseTree(Node* root) {
	if (!root) return;

	cout << root->key << " ";
	traverseTree(root->left);
	traverseTree(root->right);

	return;
}

Node* buildLevelorder() {
	int n;
	cin >> n;

	if (n == -1) return nullptr;

	queue<Node*> q;
	Node* root = new Node(n);
	q.push(root);

	int left, right;
	while (!q.empty()) {
		Node* front = q.front();
		q.pop();

		cin >> left >> right;
		if (left != -1) {
			front->left = new Node(left);
			q.push(front->left);
		}
		if (right != -1) {
			front->right = new Node(right);
			q.push(front->right);
		}
	}

	return root;
}

void traverseLevelorder(Node* root) {
	if (!root) return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* front = q.front();
		q.pop();

		cout << front->key << " ";
		if (front->left)
			q.push(front->left);
		if (front->right)
			q.push(front->right);
	}

	return;
}

vector<int> printKthLevel(Node* root, int k) {
	vector<int> kth_level;

	if (!root) kth_level;

	queue<Node*> q;
	q.push(root);

	int level = 0;
	bool level_reached = false;

	while (!q.empty()) {
		int size = q.size();

		while (size--) {
			Node* front = q.front();
			q.pop();

			if (level == k) {
				level_reached = true;

				kth_level.push_back(front->key);
			} else {
				if (front->left) {
					q.push(front->left);
				}
				if (front->right) {
					q.push(front->right);
				}
			}
		}

		level++;

		if (level_reached) break;
	}

	return kth_level;
}

int main() {
	Node* t1 = buildLevelorder();
	traverseLevelorder(t1);
	cout << endl;
	int k1 = 1;
	vector<int> kth_level_1 = printKthLevel(t1, k1);
	for (int e : kth_level_1) {
		cout << e << " ";
	}
	cout << endl;

	Node* t2 = buildLevelorder();
	traverseLevelorder(t2);
	cout << endl;
	int k2 = 2;
	vector<int> kth_level_2 = printKthLevel(t2, k2);
	for (int e : kth_level_2) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
