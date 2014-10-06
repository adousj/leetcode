#include <iostream>
#include <vector>
#include <algorithm>

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
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL) return NULL;

		ListNode prenode(0);
		prenode.next = head;
		ListNode *a;
		a = head->next;
		head->next = NULL;
		while (a != NULL)
		{
			ListNode *node = &prenode;
			while (node->next != NULL)
			{
				if (node->next->val >= a->val)
				{
					ListNode *a_tmp = a;
					a = a->next;
					a_tmp->next = node->next;
					node->next = a_tmp;
					break;
				}
				node = node->next;
			}
			if (node->next == NULL)
			{
				ListNode *a_tmp = a;
				a = a->next;
				a_tmp->next = node->next;
				node->next = a_tmp;
			}
		}

		return prenode.next;
	}
};

int main()
{
	ListNode *head = new ListNode(2);
	head->next = new ListNode(4);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(0);

	Solution s;
	head = s.insertionSortList(head);

	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}

