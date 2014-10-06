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
	void reorderList(ListNode *head) {
		if (head == NULL) return;

		vector<ListNode *> vec;
		ListNode *node = head;
		while (node != NULL)
		{
			vec.push_back(node);
			node = node->next;
		}
		int n = vec.size();
		for (int i = 0; i < n / 2; i++)
		{
			vec[i]->next = vec[n - 1 - i];
			vec[n - 1 - i]->next = vec[i + 1];
		}
		vec[n / 2]->next = NULL;
	}
};

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *node = head;
	node->next = new ListNode(1); node = node->next;
	node->next = new ListNode(2); node = node->next;
	node->next = new ListNode(3); node = node->next;
	node->next = new ListNode(4); node = node->next;
	node->next = new ListNode(5); node = node->next;

	Solution s;
	s.reorderList(head);

	node = head;
	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;

	return 0;
}

