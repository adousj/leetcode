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
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL || k==0) return head;
		ListNode pre(0);
		pre.next = head;
		ListNode *node, *last;
		node = last = head;
		int i, j;
		i = 1;
		while (last->next != NULL)
		{
			i++;
			last = last->next;
		}
		if (i == 1 || k%i==0) return head;

		j = i - k%i - 1;
		while (j--)
		{
			node = node->next;
		}
		pre.next = node->next;
		last->next = head;
		node->next = NULL;

		return pre.next;
	}
};

int main()
{
	ListNode head(0);
	ListNode *node = &head;
	node->next = new ListNode(1); node = node->next;
	//node->next = new ListNode(2); node = node->next;
	//node->next = new ListNode(3); node = node->next;
	//node->next = new ListNode(4); node = node->next;

	Solution s;
	node = s.rotateRight(&head, 2);
	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;

	return 0;
}

