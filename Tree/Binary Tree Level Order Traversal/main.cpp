#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Binary Tree Level Order Traversal

/*
 * Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 *
 * Example 1:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
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
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
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

TreeNode* buildTreeLevelOrder() {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	TreeNode* root = new TreeNode(data);

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* n = q.front();
		q.pop();

		int child_1, child_2;
		cin >> child_1 >> child_2;

		if (child_1 != -1) {
			n->left = new TreeNode(child_1);
			q.push(n->left);
		}

		if (child_2 != -1) {
			n->right = new TreeNode(child_2);
			q.push(n->right);
		}
	}

	return root;
}

void printLevelorderPerLevel(TreeNode *root) {
	queue<TreeNode *> q;

	q.push(root);
	q.push(nullptr);

	while (q.size()) {
		if (q.front()) {
			cout << q.front()->val << " ";
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

/*
 * Binary Tree Level Order Traversal
 * Input: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
 * Tree:
 * 				1
 * 			2		3
 * 		4		5		6
 * 			7
 * Level Order Traversal - BFS - Queue
 * Level Order Traversal Output: 1 2 3 4 5 6 7
 */

vector<vector<int>> levelOrder(TreeNode *root) {
	vector<vector<int>> res;
	if (!root)
		return res;
	queue<TreeNode*> q;

	q.push(root);
	int level = 0;

	while (q.size()) {
		res.push_back(vector<int>());
		int level_length = q.size();
		for (int i = 0; i < level_length; i++) {
			TreeNode *node = q.front();
			q.pop();

			res[level].push_back(node->val);

			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		level++;
	}
	return res;
}

int main() {
	TreeNode *root = buildTreeLevelOrder();

	cout << "Binary Tree Level Order Traversal:\n";
	vector<vector<int>> tree = levelOrder(root);

	for (vector<int> v : tree) {
		for (int e : v) {
			cout << e << " ";
		}
		cout << endl;
	}

	cout << endl;

	cout << "Binary Tree Level Order Traversal:\n";
	printLevelorderPerLevel(root);

	return 0;
}
