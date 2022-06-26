#include <iostream>
#include <queue>
using namespace std;

/*
 * Sum of Nodes
 *
 * Given a binary tree with N nodes. Your task is to return the sum of all N nodes.
 *
 * Input Format: In the function a pointer to the root node of the binary tree is passed.
 * Output Format: Return an integer representing sum of all nodes.
 *
 * Sample Input: 2 7 5 -1 9 -1 1 11 4 -1 -1 -1 -1 -1 -1
 * Sample Output: 39
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

int sumBT(Node* root)
{
    if (!root) return 0;

    int sum = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
    	Node* front = q.front();
    	q.pop();
    	sum += front->key;

    	if (front->left) q.push(front->left);
    	if (front->right) q.push(front->right);
    }

    return sum;
}

int main() {
	Node* t1 = buildLevelorder();
	traverseLevelorder(t1);
	cout << endl;
	cout << sumBT(t1) << endl;

	return 0;
}
