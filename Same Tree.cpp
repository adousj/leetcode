// same_tree.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		return rev_tree(p, q);
	}

	bool rev_tree(TreeNode *p, TreeNode *q)
	{
		if (p == NULL && q == NULL)
			return true;
		else if (p == NULL || q == NULL)
			return false;
		else if (p->val != q->val)
			return false;
		else
			return rev_tree(p->left, q->left) && rev_tree(p->right, q->right);
	}
};

int main()
{
	TreeNode *p = new TreeNode(1);
	TreeNode *q = new TreeNode(1);

	p->left = new TreeNode(2);
	q->right = new TreeNode(2);

	Solution s;
	cout << s.isSameTree(p, q) << endl;

	return 0;
}

