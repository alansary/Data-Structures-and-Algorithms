#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

// Inorder Successor in BST

/*
 * Given the root of a binary search tree and a node p in it, return the in-order successor
 * of that node in the BST. If the given node has no in-order successor in the tree, return
 * null.
 *
 * The successor of a node p is the node with the smallest key greater than p.val.
 *
 * Example 1:
 * Input: root = [2,1,3], p = 1
 * Output: 2
 * Explanation: 1's in-order successor node is 2. Note that both p and the return value is
 * of TreeNode type.
 *
 * Example 2:
 * Input: root = [5,3,6,2,4,null,null,1], p = 6
 * Output: null
 * Explanation: There is no in-order successor of the current node, so the answer is null.
 * Constraints:
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
 * All Nodes will have unique values.
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

TreeNode *buildTreeLevelOrder() {
	int data;
	cin >> data;

	if (data == -1) {
		return nullptr;
	}

	queue<TreeNode *> q;
	TreeNode* root = new TreeNode(data);
	q.push(root);

	while (!q.empty()) {
		TreeNode *n = q.front();
		q.pop();
		if (n) {
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
	}

	return root;
}

void printLevelorderPerLevel(TreeNode *root) {
	queue<TreeNode *> q;

	q.push(root);
	q.push(nullptr);

	while (q.size()) {
		if (q.front()) {
			cout <<q.front()->val<<" ";
			if (q.front()->left) {
				q.push(q.front()->left);
			}
			if (q.front()->right) {
				q.push(q.front()->right);
			}
			q.pop();
		} else {
			cout <<"\n";
			q.pop();
			if (!q.empty()) {
				q.push(nullptr); // Corner Case
			}
		}
	}
	cout <<endl;
}

/*
 * Right child - right child
 * Else, check parent:
 * If lies on left sub-tree - direct parent
 * If lies on right sub-tree - null
 */

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	// Inorder Traverse
	stack<TreeNode *> s;
	vector<TreeNode *> tree;

	if (!root) {
		return nullptr;
	}

	TreeNode* curr = root;

	while (curr || !s.empty()) {
		while (curr) {
			if (curr->val != -1)
				s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		tree.push_back(curr);
		curr = curr->right;
	}

	cout << "Output: ";
	for (int i = 0; i < tree.size(); i++) {
		cout << tree[i]->val << " ";
	}
	cout << endl;

	for (int i = 0; i < tree.size(); i++) {
		if (tree[i]->val == p->val) {
			if (i == tree.size() - 1) {
				return nullptr;
			} else {
				return tree[i+1];
			}
		}
	}
}

TreeNode * returnNode(TreeNode *root, int key) {
	if (!root) {
		return nullptr;
	}

	if (root->val == key) {
		return root;
	} else if (key < root->val) {
		return returnNode(root->left, key);
	} else {
		return returnNode(root->right, key);
	}
}

int main() {
	/*
	 * Input: 5 3 6 2 4 -1 -1 1 -1 -1 -1 -1 -1
	 * Tree:
	 * 					5
	 * 			3				6
	 * 		2		4
	 * 	1
	 *
	 * Input: 5 3 6 2 4 -1 -1 1 -1 -1 -1 -1 -1
	 * P: 6
	 * Output: nullptr
	 *
	 * Input: 2 1 3 -1 -1 -1 -1
	 * P: 1
	 * Output: 2
	 *
	 * Input: 0 -1 -1
	 * P: 0
	 * Output: nullptr
	 *
	 * Input: 2 1 -1 -1 -1
	 * P: 2
	 * Output: nullptr
	 *
	 * Input: 5 3 6 1 4 -1 -1 -1 2 -1 -1 -1 -1 -1 -1
	 * P: 4
	 * Output: 5
	 *
	 * Input: 5 3 6 2 4 -1 -1 1 -1 -1 -1 -1 -1 2 1 3 -1 -1 -1 -1 0 -1 -1 2 1 -1 -1 -1 5 3 6 1 4 -1 -1 -1 2 -1 -1 -1 -1 -1 -1
	 */

	vector<int> P = {6, 1,  0, 2, 4};
	for (int p : P) {
		TreeNode *root = buildTreeLevelOrder();

//		printLevelorderPerLevel(root);
//		cout << endl;

		TreeNode *successor = inorderSuccessor(root, returnNode(root, p));

		if (successor) {
			cout << "Successor: " << successor->val << endl;
		} else {
			cout << "Successor Not Found!" << endl;
		}
	}

	return 0;
}
