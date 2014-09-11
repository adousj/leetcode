// Minimum Depth of Binary Tree.cpp : 定义控制台应用程序的入口点。
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
	int minDepth(TreeNode *root) {
		if (root == NULL) return 0;

		min_dep = 0;
		trav(root, 1);

		return min_dep;
	}

	void trav(TreeNode *node, int n)
	{
		if (node->left == NULL && node->right == NULL)
		{
			if (min_dep == 0 || min_dep>n )
				min_dep = n ;
		}
		else
		{
			if (node->left != NULL)
				trav(node->left, n + 1);
			if (node->right != NULL)
				trav(node->right, n + 1);
		}
	}
private:
	int min_dep;
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(3);

	Solution s;
	cout << s.minDepth(root) << endl;

	return 0;
}

