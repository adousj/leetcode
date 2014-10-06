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
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) return NULL;

		ListNode prehead(head->val-1);
		prehead.next = head;
		ListNode *node = &prehead;
		while (node->next != NULL)
		{
			int num = 0;
			ListNode *tmp = node->next->next;
			while (tmp != NULL)
			{
				if (tmp->val == node->next->val)
				{
					num++;
					tmp = tmp->next;
				}
				else
				{
					break;
				}
			}
			if (num > 0)
			{
				node->next = tmp;
			}
			else
			{
				node = node->next;
			}
		}

		return prehead.next;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(3);

	Solution s;
	head = s.deleteDuplicates(head);

	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}

