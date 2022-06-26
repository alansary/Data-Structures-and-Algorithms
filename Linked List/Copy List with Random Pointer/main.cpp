#include <iostream>
using namespace std;

// Copy List with Random Pointer

/*
 * A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
 * Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
 * For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
 * Return the head of the copied linked list.
 * The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
 * Your code will only be given the head of the original linked list.
 * Example 1:
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Example 2:
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 * Example 3:
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 * Constraints:
 * 0 <= n <= 1000
 * -10^4 <= Node.val <= 10^4
 * Node.random is null or is pointing to some node in the linked list.
 */

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
	if (head) {
		Node* h = head;

		Node* list = new Node(head->val);
		head = head->next;

		// Create nodes and copy val and next
		while (head) {
			Node* n = new Node(head->val);
			Node* ptr = list;

			while (ptr->next) {
				ptr = ptr->next;
			}
			ptr->next = n;

			head = head->next;
		}

		// Copy random connections
		head = h; // Reset the head
		Node* ptr = list;
		while (head) {
			if (!head->random) {
				ptr->random = nullptr;
			} else {
				// Check which node is random points to
				Node* ptr1 = h;
				Node* ptr2 = list;
				while (ptr1 != head->random) {
					ptr1 = ptr1->next;
					ptr2 = ptr2->next;
				}
				ptr->random = ptr2;
			}
			ptr = ptr->next;
			head = head->next;
		}

		return list;
	}

	return nullptr;
}

int main() {
	Node* list = new Node(7);
	Node* list_node2 = new Node(13);
	list->next = list_node2;
	Node* list_node3 = new Node(11);
	list_node2->next = list_node3;
	Node* list_node4 = new Node(10);
	list_node3->next = list_node4;
	Node* list_node5 = new Node(1);
	list_node4->next = list_node5;

	list->random = nullptr;
	list_node2->random = list;
	list_node3->random = list_node5;
	list_node4->random = list_node3;
	list_node5->random = list;

	Node* head = copyRandomList(list);

	// 7 (-1) -> 13 (7) -> 11 (1) -> 10 (11) -> 1 (7) ->
	while (head) {
		cout << head->val << " (" << (head->random ? head->random->val : -1) << ")" << " -> ";
		head = head->next;
	}
	cout << endl;

	return 0;
}
