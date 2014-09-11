// Remove Nth Node From End of List.cpp : 定义控制台应用程序的入口点。
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
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (head == NULL || head->next == NULL) return NULL;

		vector<ListNode*> vec;
		ListNode *node = head;
		while (node != NULL)
		{
			vec.push_back(node);
			node = node->next;
		}

		if (n == vec.size())
		{
			return vec[1];
		}
		else if (n==1)
		{
			vec[vec.size() - 2]->next = NULL;
			return head;
		}
		else
		{
			vec[vec.size() - n - 1]->next = vec[vec.size() - n + 1];
			return head;
		}
	}
};

int main()
{
	ListNode *root = new ListNode(1);

	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = new ListNode(5);

	Solution s;
	
	ListNode *node = s.removeNthFromEnd(root, 2);;
	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;

	return 0;
}

