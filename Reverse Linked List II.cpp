// Reverse Linked List II.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (head == NULL) return NULL;
		ListNode root(0);
		root.next = head;
		ListNode *prenode = &root;
		int i = 1;
		while (i < m)
		{
			prenode = prenode->next;
			i++;
		}
		ListNode *last = NULL;
		ListNode *node = prenode->next;
		while (i <= n)
		{
			ListNode *next = node->next;
			node->next = last;
			last = node;
			node = next;
			i++;
		}
		prenode->next->next = node;
		prenode->next = last;

		return root.next;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	Solution s;
	head = s.reverseBetween(head, 2, 5);

	return 0;
}

