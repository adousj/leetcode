// maxium_depth_of_binary_tree.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

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
	int maxDepth(TreeNode *root)
	{
		max_depth = 0;
		if (root == NULL) return max_depth;
		rev_depth(root, 1);
		return max_depth;
	}

	void rev_depth(TreeNode *node, int depth)
	{

		if (node->left != NULL)
		{
			rev_depth(node->left, depth + 1);
		}
		if (node->right != NULL)
		{
			rev_depth(node->right, depth + 1);
		}
		if (node->right == NULL && node->left == NULL && depth > max_depth)
			max_depth = depth;
	}

private:
	int max_depth;
};

int main()
{
	TreeNode *root = new TreeNode(1);

	vector<TreeNode> nodes;
	for (int i = 0; i < 10; i++)
	{
		nodes.push_back(TreeNode(i));
	}

	root->left = &nodes[0];
	root->right = &nodes[1];
	root->right->left = &nodes[2];
	root->right->left->right = &nodes[3];

	root = NULL;

	Solution s;
	cout << s.maxDepth(root) << endl;

	return 0;
}

