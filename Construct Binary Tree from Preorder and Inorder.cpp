// Construct Binary Tree from Preorder and Inorder.cpp : 定义控制台应用程序的入口点。
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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.size() == 0|| preorder.size()!=inorder.size()) return NULL;
		return trav(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}

	TreeNode* trav(vector<int>::iterator a, vector<int>::iterator b, vector<int>::iterator c, vector<int>::iterator d)
	{
		if (a >= b) return NULL;

		TreeNode *head = new TreeNode(*a);
		vector<int>::iterator e = find(c, d, *a);
		head->left = trav(a + 1, e-c+a+1, c, e);
		head->right = trav(e-c+a+1, b, e+1, d);
		return head;
	}
};

int main()
{
	int A[] = { 1, 2, 4, 5, 3, 6 };
	int B[] = { 4, 2, 5, 1, 3, 6 };

	vector<int> pre(A, A + sizeof(A) / sizeof(int));
	vector<int> in(B, B + sizeof(B) / sizeof(int));

	Solution s;
	TreeNode *node = s.buildTree(pre, in);

	return 0;
}

