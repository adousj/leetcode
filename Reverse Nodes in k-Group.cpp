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
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == NULL || k==1) return head;

		ListNode prehead(0);
		prehead.next = head;
		ListNode *pre = &prehead;
		ListNode *node = prehead.next;
		while (node != NULL)
		{
			int num = 1;
			while (node != NULL && num<k)
			{
				node = node->next;
				num++;
			}
			if (node != NULL && num == k)
			{
				ListNode *next;
				next = node->next;
				node = pre->next;
				for (int i = 0; i < k; i++)
				{
					ListNode *tmp = node->next;
					node->next = next;
					next = node;
					node = tmp;
				}
				ListNode *tmp = pre->next;
				pre->next = next;
				pre = tmp;
			}
		}

		return prehead.next;
	}
};


int main()
{
	ListNode *head = new ListNode(1);

	ListNode *node = head;
	for (int i = 2; i < 6; i++)
	{
		node->next = new ListNode(i);
		node = node->next;
	}

	Solution s;
	node = s.reverseKGroup(head, 3);

	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;

	return 0;
}

