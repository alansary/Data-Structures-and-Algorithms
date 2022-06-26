#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Binary Tree Inorder Traversal

/*
 * Given the root of a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example 1:
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
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

void printInorder(TreeNode *root) {
	if (!root) {
		return;
	}

	printInorder(root->left);
	cout << root->val << " ";
	printInorder(root->right);
}

/*
 * Left -> Root -> Right
 * Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 * Ouput: 4 2 7 5 1 3 6
 * Input: [1, null, 2, 3]
 * Output:
 * 				1
 * 			2		3
 * 		4		5		6
 * 			7
 */

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> tree;
	stack<TreeNode *> s;

	if (!root) {
		return tree;
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

	return tree;
}

int main() {
	TreeNode* root = buildTree();

	vector<int> tree = inorderTraversal(root);

	for (int e : tree) {
		cout << e << " ";
	}

	cout << endl;

	printInorder(root);

	cout << endl;

	return 0;
}
