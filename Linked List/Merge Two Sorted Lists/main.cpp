#include <iostream>
using namespace std;

// Merge Two Sorted Lists

/*
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
 * Example 1:
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 * Example 2:
 * Input: list1 = [], list2 = []
 * Output: []
 * Example 3:
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 * Constraints:
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both list1 and list2 are sorted in non-decreasing order.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	if (list1 && !list2) {
		return list1;
	} else if (list2 && !list1) {
		return list2;
	} else {
		ListNode* head = list1;

		// while linked lists are not empty
		while (list1 && list2) {
			// case list1 item <= list2 item
			if (list1->val <= list2->val) {
				if (list1->next) {
					// case next item exists
					while (list1->next && list1->next->val <= list2->val) {
						list1 = list1->next;
					}

					ListNode* n = list2;
					list2 = list2->next;
					n->next = list1->next;
					list1->next = n;
				} else {
					// case next item doesn't exist
					ListNode* n = list2;
					list2 = list2->next;
					n->next = nullptr;
					list1->next = n;
				}

				// move list1 pointer ahead
				if (list1->next && list1->next->next) {
					list1 = list1->next->next;
				} else {
					list1 = list1->next;
				}
			} else {
				if (list1 == head) {
					ListNode* n = list2;
					list2 = list2->next;
					n->next = head;
					head = n;
				} else {
					ListNode* ptr = head;
					while (ptr->next != list1) {
						ptr = ptr->next;
					}
					ptr->next = list2;
					list2 = list2->next;
					ptr->next->next = list1;
				}
			}
		}

		return head;
	}
}

int main() {
//	ListNode *list1 = new ListNode(1);
//	ListNode *list1_node2 = new ListNode(2);
//	list1->next = list1_node2;
//	ListNode *list1_node3 = new ListNode(4);
//	list1_node2->next = list1_node3;
//	ListNode *list1_node4 = new ListNode(7);
//	list1_node3->next = list1_node4;
//
//	ListNode *list2 = new ListNode(1);
//	ListNode *list2_node2 = new ListNode(3);
//	list2->next = list2_node2;
//	ListNode *list2_node3 = new ListNode(4);
//	list2_node2->next = list2_node3;
//	ListNode *list2_node4 = new ListNode(5);
//	list2_node3->next = list2_node4;
//	ListNode *list2_node5 = new ListNode(6);
//	list2_node4->next = list2_node5;

//	ListNode *list1 = new ListNode(2);
//
//	ListNode *list2 = new ListNode(1);

	ListNode *list1 = new ListNode(-9);
	ListNode *list1_node2 = new ListNode(3);
	list1->next = list1_node2;

	ListNode *list2 = new ListNode(5);
	ListNode *list2_node2 = new ListNode(7);
	list2->next = list2_node2;

	ListNode* head = mergeTwoLists(list1, list2);

	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << endl;

	return 0;
}
