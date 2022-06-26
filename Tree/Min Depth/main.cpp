#include <iostream>
#include <queue>
using namespace std;

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
	int level = 0;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			Node* front = q.front();
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
 * Min Depth
 *
 * Given a binary tree with N nodes. Your task is to find the minimum depth.
 *
 * Input Format: In the function a pointer to the root node of the binary tree is passed.
 * Output Format: Return an integer representing minimum depth.
 *
 * Sample Input: 2 7 5 -1 9 -1 1 11 4 -1 -1 -1 -1 -1 -1
 * 				2
 * 			  /   \
 * 			 7     5
 * 			  \		\
 * 			   9	 1
 * 			 /   \
 * 			11    4
 * Sample Output: 3
 * Explanation: Minimum depth is between nodes 2 and 1 since minimum depth is defined as
 * the number of nodes along the shortest path from the root node down to the nearest leaf
 * node.
 */

int height(Node *root) {
	if (!root) return 0;

	return max(height(root->left), height(root->right)) + 1;
}

int minDepth(Node *root) {
	if (!root) return 0;

	return min(height(root->left), height(root->right)) + 1;
}

int main() {
	Node* t1 = buildLevelorder();
	traverseLevelorder(t1);
	cout << minDepth(t1);

	return 0;
}
