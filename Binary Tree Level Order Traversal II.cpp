// Binary Tree Level Order Traversal II.cpp : 定义控制台应用程序的入口点。
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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		result = new vector<vector<int> >;

		trav(root, 1);

		vector<vector<int> > vec;
		for (int i = result->size() - 1; i >= 0; i--)
		{
			vec.push_back((*result)[i]);
		}
		delete result;

		return vec;
	}

	void trav(TreeNode *node, int n)
	{
		if (node == NULL) return;
		
		while (result->size() < n) result->push_back(vector<int>());

		(*result)[n-1].push_back(node->val);

		trav(node->left, n + 1);
		trav(node->right, n + 1);
	}
private:
	vector<vector<int> > *result;
};

int main()
{
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;
	vector<vector<int> > result = s.levelOrderBottom(root);

	return 0;
}

