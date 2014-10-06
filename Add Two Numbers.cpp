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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if (l1 == NULL && l2 == NULL) return NULL;

		ListNode prehead(0);
		ListNode *node = &prehead;
		int t = 0;
		while (l1 != NULL || l2 != NULL || t!=0)
		{
			node->next = new ListNode(0);
			node = node->next;
			node->val += t;
			if (l1 != NULL)
			{
				node->val += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				node->val += l2->val;
				l2 = l2->next;
			}
			t = node->val / 10;
			node->val %= 10;
		}

		return prehead.next;
	}
};

int main()
{
	ListNode *head1 = new ListNode(2);
	head1->next = new ListNode(4);
	head1->next->next = new ListNode(3);

	ListNode *head2 = new ListNode(5);
	head2->next = new ListNode(6);
	head2->next->next = new ListNode(4);
	head2->next->next->next = new ListNode(1);

	Solution s;
	ListNode *node = s.addTwoNumbers(head1, head2);

	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;

	return 0;
}

