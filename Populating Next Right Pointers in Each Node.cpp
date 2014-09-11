// PopulatingNextRightPointersinEachNode.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL) return;
		vector<TreeLinkNode*> vec;
		vec.push_back(new TreeLinkNode(0));
		vec.push_back(root);
		for (int i = 1; i < vec.size(); i++)
		{
			TreeLinkNode *node = vec[i];
			if (node->left != NULL)
				vec.push_back(node->left);
			if (node->right != NULL)
				vec.push_back(node->right);
		}
		for (int i = 2; i < vec.size(); i++)
		{
			int sq = 1;
			while (sq < i) sq *= 2;
			if (i == sq - 1)
				vec[i]->next = NULL;
			else
				vec[i]->next = vec[i + 1];
		}
	}
};

int main()
{
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right->left = new TreeLinkNode(6);
	root->right->right = new TreeLinkNode(7);

	Solution s;
	s.connect(root);

	return 0;
}

