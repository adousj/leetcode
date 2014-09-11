// ConvertSortedArraytoBinarySearchTree.cpp : 定义控制台应用程序的入口点。
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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		if (num.size() == 0) return NULL;

		int center = num.size()/2;
		TreeNode *root = new TreeNode(num[center]);

		root->left = subBST(num, 0, center - 1);
		root->right = subBST(num, center + 1, num.size()-1);

		return root;
	}

	TreeNode *subBST(vector<int> &num, int a, int b)
	{
		if (a > b)
			return NULL;
		
		int center = (a + b) / 2;
		TreeNode *node = new TreeNode(num[center]);

		node->left = subBST(num, a, center - 1);
		node->right = subBST(num, center + 1, b);

		return node;
	}
};

int main()
{
	int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	vector<int> vec(A, A+sizeof(A)/sizeof(int));

	Solution s;
	s.sortedArrayToBST(vec);

	return 0;
}

