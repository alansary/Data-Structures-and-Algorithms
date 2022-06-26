#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
 * Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 * Tree:
 * 				1
 * 			2		3
 * 		4		5		6
 * 			7
 * Preorder Traversal: Root -> Left -> Right
 * Preorder Traversal Output: 1 2 4 5 7 3 6
 * Inorder Traversal: Left -> Root -> Right
 * Inorder Traversal Output: 4 2 7 5 1 3 6
 * Postorder Traversal: Left -> Right -> Root
 * Postorder Traversal Output: 4 7 5 2 6 3 1
 * Level Order Traversal - BFS - Queue
 * Level Order Traversal Output: 1 2 3 4 5 6 7
 *
 * Build Tree - Level Order
 * Input: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
 * Tree:
 * 				1
 * 			2		3
 * 		4		5		6
 * 			7
 * Level Order Traversal - BFS - Queue
 * Level Order Traversal Output: 1 2 3 4 5 6 7
 */

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

// Preorder build of the tree
// Root, Left, Right
Node* buildTree() {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	Node* n = new Node(data);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void printPreorder(Node *root) {
	if (!root) {
//		cout << "-1 ";
		return;
	}

	cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void preorderTraversalIterative(Node* root) {
	stack<Node*> s;

	if (!root) return;

	s.push(root);
	while (!s.empty()) {
		Node* top = s.top();
		cout << top->data << " ";
		s.pop();

		if (top->right)
			s.push(top->right);
		if (top->left)
			s.push(top->left);
	}

	return;
}

void printInorder(Node *root) {
	if (!root) {
		return;
	}

	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

void inorderTraversalIterative(Node* root) {
	stack<Node*> s;
	if (!root) return;

	Node* curr = root;
	while (curr || !s.empty()) {
		while (curr) {
			s.push(curr);
			curr = curr->left;
		}

		Node* top = s.top();
		s.pop();
		cout << top->data << " ";
		curr = top->right;
	}

	return;
}

void printPostorder(Node *root) {
	if (!root) {
		return;
	}

	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->data << " ";
}

void printLevelorder(Node *root) {
	queue<Node *> q;

	q.push(root);

	while (q.size()) {
		cout << q.front()->data << " ";
		if (q.front()->left) {
			q.push(q.front()->left);
		}
		if (q.front()->right) {
			q.push(q.front()->right);
		}
		q.pop();
	}
	cout << endl;
}

void printLevelorderPerLevel(Node *root) {
	queue<Node *> q;

	q.push(root);
	q.push(nullptr);

	while (q.size()) {
		if (q.front()) {
			cout << q.front()->data << " ";
			if (q.front()->left) {
				q.push(q.front()->left);
			}
			if (q.front()->right) {
				q.push(q.front()->right);
			}
			q.pop();
		} else {
			cout << "\n";
			q.pop();
			if (!q.empty()) {
				q.push(nullptr); // Corner Case
			}
		}
	}
	cout << endl;
}

Node* buildTreeLevelOrder() {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	Node* root = new Node(data);

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* n = q.front();
		q.pop();

		int child_1, child_2;
		cin >> child_1 >> child_2;

		if (child_1 != -1) {
			n->left = new Node(child_1);
			q.push(n->left);
		}

		if (child_2 != -1) {
			n->right = new Node(child_2);
			q.push(n->right);
		}
	}

	return root;
}

int height(Node *root) {
	if (!root) {
		return 0;
	}

	int h1 = height(root->left);
	int h2 = height(root->right);

	return 1 + max(h1, h2);
}

// O(n^2)
int diameter(Node *root) {
	if (!root) {
		return 0;
	}

	int D1 = height(root->left) + height(root->right);
	int D2 = diameter(root->left);
	int D3 = diameter(root->right);

	return max(D1, max(D2, D3));
}

class HDPair {
public:
	int height;
	int diameter;
};

// O(n)
HDPair diameterOptimized(Node *root) {
	HDPair p;
	if (!root) {
		p.height = 0;
		p.diameter = 0;
		return p;
	}

	HDPair left = diameterOptimized(root->left);
	HDPair right = diameterOptimized(root->right);

	p.height = max(left.height, right.height) + 1;
	p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

	return p;
}

int main() {
	Node* root = buildTree();

	cout << "Preorder Traversal: ";
	printPreorder(root);

	cout << endl;

	cout << "Preorder Traversal Iterative: ";
	preorderTraversalIterative(root);

	cout << endl;

	cout << "Inorder Traversal: ";
	printInorder(root);

	cout << endl;

	cout << "Inorder Traversal Iterative: ";
	inorderTraversalIterative(root);

	cout << endl;

	cout << "Postorder Traversal: ";
	printPostorder(root);

	cout << endl;

	cout << "Level Order Traversal: ";
	printLevelorder(root);

	cout << "Level Order Traversal Per Level:\n";
	printLevelorderPerLevel(root);


	cout << "Build Tree - Level Order\n";
	Node* r = buildTreeLevelOrder();

	cout << endl;

	cout << "Level Order Traversal Per Level:\n";
	printLevelorderPerLevel(r);

	cout << endl;

	cout << "Height of tree: " << height(r) << endl;
	cout << "Diameter of tree: " << diameter(r) << endl;
	cout << "Diameter of tree (Optimized): " << diameterOptimized(r).diameter << endl;

	return 0;
}
