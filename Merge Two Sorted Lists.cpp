// MergeTwoSortedLists.cpp : 定义控制台应用程序的入口点。
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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode head(0);
		ListNode *l3 = &head;

		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				l3->next = l1;
				l3 = l3->next;
				l1 = l1->next;
			}
			else
			{
				l3->next = l2;
				l3 = l3->next;
				l2 = l2->next;
			}
		}
		
		if (l1 == NULL)
			l3->next = l2;
		else if (l2 == NULL)
			l3->next = l1;
		
		return head.next;
	}
};

int main()
{
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(3);
	l1->next->next = new ListNode(7);

	ListNode *l2 = new ListNode(2);
	l2->next = new ListNode(4);
	l2->next->next = new ListNode(5);
	l2->next->next->next = new ListNode(6);

	Solution s;
	ListNode *l3 = s.mergeTwoLists(l1, l2);

	while (l3 != NULL)
	{
		cout << l3->val << " ";
		l3 = l3->next;
	}
	cout << endl;

	return 0;
}

