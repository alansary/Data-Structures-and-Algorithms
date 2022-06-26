#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Binary Tree Preorder Traversal

/*
 * Given the root of a binary tree, return the preorder traversal of its nodes' values.
 *
 * Example 1:
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
 *
 * Example 2:
 * Input: root = []
 * Output: []
 *
 * Example 3:
 * Input: root = [1]
 * Output: [1]
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = nullptr;
	}
};

// Preorder build of the tree
// Root, Left, Right
TreeNode* buildTree() {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	TreeNode* n = new TreeNode(data);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void printPreorder(TreeNode *root) {
	if (!root) {
//		cout << "-1 ";
		return;
	}

	cout << root->val << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}

/*
 * Root -> Left -> Right
 * DFS - Stack
 * Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 * Output: 1 2 4 5 7 3 6
 * Input: [1, null, 2, 3]
 * Output:
 * 				1
 * 			2		3
 * 		4		5		6
 * 			7
 */
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> tree;

	stack<TreeNode *> s;
	s.push(root);

	while (!s.empty()) {
		TreeNode* top = s.top();
		s.pop();
		if (top && top->val != -1) {
			tree.push_back(top->val);

			if (top->right && top->right->val != -1) {
				s.push(top->right);
			}
			if (top->left && top->left->val != -1) {
				s.push(top->left);
			}
		}
	}

	return tree;
}

int main() {
	TreeNode* root = buildTree();

	printPreorder(root);
	cout << endl;

	vector<int> tree = preorderTraversal(root);

	for (int e : tree) {
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
