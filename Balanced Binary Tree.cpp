// BalancedBinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <map>

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
	bool isBalanced(TreeNode *root) {
		if (root == NULL)
			return true;

		return maxDepth(root) != -1;
	}

	int maxDepth(TreeNode *node)
	{
		if (node == NULL) return 0;

		int left_depth = maxDepth(node->left);
		int right_depth = maxDepth(node->right);

		if (left_depth==-1 || right_depth==-1 || left_depth - right_depth > 1 || left_depth - right_depth<-1)
			return -1;

		return (left_depth > right_depth ? left_depth : right_depth) + 1;
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);

	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(4);
	root->right->right->left = new TreeNode(5);

	Solution s;
	cout << s.isBalanced(root) << endl;
	return 0;
}

