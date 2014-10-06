// Validate Binary Search Tree.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <algorithm>
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
	bool isValidBST(TreeNode *root) {
		if (root == NULL) return true;
		vec = new vector<int>;
		trav(root);
		for (int i = 1; i < vec->size(); i++)
		{
			if (vec->at(i) <= vec->at(i - 1))
				return false;
		}
		delete vec;
		return true;
	}

	void trav(TreeNode *node)
	{
		if (node == NULL) return;
		trav(node->left);
		vec->push_back(node->val);
		trav(node->right);
	}
private:
	vector<int> *vec;
};


int main()
{
	TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(0);
	/*root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(3);
*/
	Solution s;
	cout << s.isValidBST(root) << endl;

	return 0;
}

