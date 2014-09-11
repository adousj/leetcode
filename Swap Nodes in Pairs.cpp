// SwapNodesinPairs.cpp : 定义控制台应用程序的入口点。
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
	ListNode *swapPairs(ListNode *head) {
		if (head == NULL || head->next==NULL) return head;

		ListNode *l1, *l2, *l0;
		l1 = head;
		l2 = head->next;
		head = l2;

		l0 = head;
		if (l1 != NULL && l2 != NULL)
		{
			l1->next = l2->next;
			l2->next = l1;
			l0 = l1;
			l1 = l1->next;
			if (l1 != NULL) l2 = l1->next;
		}

		while (l1 != NULL && l2!=NULL)
		{
			l0->next = l2;
			l1->next = l2->next;
			l2->next = l1;
			l0 = l1;
			l1 = l1->next;
			if (l1!=NULL) l2 = l1->next;
		}

		return head;
	}
};

int main()
{
	ListNode *root = new ListNode(1);
	
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);

	Solution s;
	s.swapPairs(root);

	return 0;
}

