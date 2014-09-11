// RemoveDuplicatesfromSortedList.cpp : 定义控制台应用程序的入口点。
//

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
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *node = head;
		while(node != NULL)
		{
			if (node->next != NULL && node->next->val == node->val)
			{
				ListNode *tmp = node->next;
				node->next = node->next->next;
				delete tmp;
			}
			else
				node = node->next;
		}

		return head;
	}
};

int main()
{
	int a[] = { 1, 1, 2, 3, 3 };
	vector<int> vec(a, a + sizeof(a) / sizeof(int));

	ListNode *root = new ListNode(vec[0]);
	ListNode *node = root;
	for (int i = 1; i < vec.size(); i++)
	{
		node->next = new ListNode(vec[i]);
		node = node->next;
	}

	Solution s;
	node = s.deleteDuplicates(root);

	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}


	return 0;
}

