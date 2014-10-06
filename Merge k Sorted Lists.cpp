#include <iostream>
#include <vector>

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
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		vector<ListNode *> new_lists;

		if (lists.size() == 0)
			return NULL;
		else if (lists.size() == 1)
			return lists[0];

		for (int i = 0; i < lists.size()-1; i += 2)
		{
			new_lists.push_back( merge2(lists[i], lists[i + 1]) );
		}

		if (lists.size() % 2 == 1)
			new_lists.push_back(lists[lists.size() - 1]);


		return mergeKLists(new_lists);
	}

	ListNode * merge2(ListNode *l1, ListNode *l2)
	{
		ListNode head(0);
		ListNode *node = &head;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				node->next = l1;
				node = l1;
				l1 = l1->next;
			}
			else
			{
				node->next = l2;
				node = l2;
				l2 = l2->next;
			}
		}
		if (l1 == NULL)
			node->next = l2;
		if (l2 == NULL)
			node->next = l1;

		return head.next;
	}
};

ListNode * build_list(int A[], int n)
{
	ListNode head(0);
	ListNode *node = &head;
	for (int i = 0; i < n; i++)
	{
		node->next = new ListNode(A[i]);
		node = node->next;
	}
	return head.next;
}

int main()
{
	int A1[] = { 1,4,7 };
	int A3[] = { 2, 5, 8 };
	int A2[] = { 3, 6, 9 };

	vector<ListNode *> vec;
	vec.push_back(build_list(A1, sizeof(A1) / sizeof(int)));
	vec.push_back(build_list(A2, sizeof(A2) / sizeof(int)));
	vec.push_back(build_list(A3, sizeof(A3) / sizeof(int)));

	Solution s;
	ListNode *node = s.mergeKLists(vec);
	
	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;

	return 0;
}

