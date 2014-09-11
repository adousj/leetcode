// Binary_Tree_Inorder_Traversal.cpp : 定义控制台应用程序的入口点。
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
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> vec;
		in_tr(vec, root);
		return vec;
	}

	void in_tr(vector<int> &vec, TreeNode *node)
	{
		if (node == NULL) return;
		in_tr(vec, node->left);
		vec.push_back(node->val);
		in_tr(vec, node->right);
	}
};

int main()
{
	TreeNode *head = new TreeNode(1);

	head->right = new TreeNode(2);
	head->right->left = new TreeNode(3);

	Solution s;
	vector<int> vec = s.inorderTraversal(head);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;


	return 0;
}

