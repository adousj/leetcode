// Binary_Tree_Preorder_Traversal.cpp : 定义控制台应用程序的入口点。
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
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> vec;
		pre_tr(root, vec);
		return vec;
	}

	void pre_tr(TreeNode *node, vector<int> &vec)
	{
		if (node == NULL) return;
		vec.push_back(node->val);
		pre_tr(node->left, vec);
		pre_tr(node->right, vec);
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution s;
	vector<int> vec = s.preorderTraversal(root);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;

	return 0;
}

