#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Validate Binary Search Tree

/*
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 *
 * A valid BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 * Example 1:
 * Input: root = [2,1,3]
 * Input: 2 1 -1 -1 3 -1 -1
 * Output: true
 *
 * Example 2:
 * Input: root = [5,1,4,null,null,3,6]
 * Input: 5 1 -1 -1 4 3 -1 -1 6 -1 -1
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 *
 * Example 3:
 * Input: 1 1 -1 -1 -1
 * Output: false
 *
 * Example 4:
 * Input: 5 4 -1 -1 6 3 -1 -1 7 -1 -1
 * Output: false
 *
 * Constraints:
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
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

// Preorderbuild of the tree
// Root, Left, Right
TreeNode* buildTree() {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	TreeNode *n = new TreeNode(data);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void printInorder(TreeNode *root) {
	if (!root) {
		return;
	}

	printInorder(root->left);
	cout << root->val << " ";
	printInorder(root->right);
}

bool isValidBST(TreeNode *root) {
	vector<int> tree;
	stack<TreeNode*> s;

	if (!root) {
		return true;
	}

	TreeNode *curr = root;
	while ((curr != nullptr && curr->val != -1) || !s.empty()) {
		while (curr != nullptr && curr->val != -1) {
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		tree.push_back(curr->val);
		curr = curr->right;
	}

	int curr_num = tree[0];
	for (int i = 1; i < tree.size(); i++) {
		if (tree[i] <= curr_num) {
			return false;
		}
		curr_num = tree[i];
	}

	return true;
}

int main() {
	TreeNode *root = buildTree();

	printInorder(root);
	cout << endl;

	cout << isValidBST(root) << endl;

	return 0;
}
