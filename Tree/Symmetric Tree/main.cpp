#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	int key;
	Node *left;
	Node *right;

	Node(int key) {
		this->key = key;
		left = right = nullptr;
	}
};

Node* buildLevelorder() {
	int n;
	cin >> n;

	if (n == -1)
		return nullptr;

	queue<Node*> q;
	Node *root = new Node(n);
	q.push(root);

	int left, right;
	while (!q.empty()) {
		Node *front = q.front();
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

void traverseLevelorder(Node *root) {
	if (!root)
		return;

	queue<Node*> q;
	q.push(root);
	int level = 0;

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
		level++;
	}

	return;
}

/*
 * Symmetric Tree
 *
 * Given a binary tree with N nodes. Your task is to check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 * Input Format: In the function a pointer to the root node of the binary tree is passed.
 * Output Format: Return true if symmetric otherwise return false.
 *
 * Sample Input: 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
 * 				1
 * 			  /   \
 * 			 2	   2
 * 		    / \   / \
 * 		   3   4 4   3
 * Sample Output: true
 *
 * Sample Input: 1 2 2 -1 3 -1 3 -1 -1 -1 -1
 * 					1
 * 				  /   \
 * 				 2     2
 * 				 \	    \
 * 				  3	     3
 * Sample Output: false
 */

bool isSymmetric(Node *root) {
	queue<Node*> q1;
	queue<Node*> q2;
	if (root == NULL || (root->right == NULL && root->left == NULL))
		return true;
	if (root->right == NULL || root->left == NULL)
		return false;
	q1.push(root->left);
	q2.push(root->right);
	while (!q1.empty() && !q2.empty()) {
		Node *f1 = q1.front();
		q1.pop();
		Node *f2 = q2.front();
		q2.pop();
		if (q1.empty() && !q2.empty())
			return false;
		if (!q1.empty() && q2.empty())
			return false;
		if (f1->left == NULL && f2->right != NULL)
			return false;
		if (f1->left != NULL && f2->right == NULL)
			return false;
		if (f1->key != f2->key)
			return false;
		if (f1->left)
			q1.push(f1->left);
		if (f1->right)
			q1.push(f1->right);
		if (f2->right)
			q2.push(f2->right);
		if (f2->left)
			q2.push(f2->left);
	}
	if (q1.empty() && q2.empty())
		return true;
	return false;
}

int main() {
	Node *t1 = buildLevelorder();
	traverseLevelorder(t1);
	cout << isSymmetric(t1) << endl;

	return 0;
}
