// Sum Root to Leaf Numbers.cpp : 定义控制台应用程序的入口点。
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
	int sumNumbers(TreeNode *root) {
		if (root == NULL) return 0;

		sum = 0;
		nums = new vector<int>;
		trav(root, 1);
		delete nums;
		return sum;
	}

	void trav(TreeNode *node, int n)
	{
		if (node->left == NULL && node->right == NULL)
		{
			int tmp = 0;
			for (int i = 0; i < n-1; i++)
			{
				tmp = tmp * 10 + (*nums)[i];
			}
			tmp = tmp * 10 + node->val;
			sum += tmp;
		}
		else
		{
			while (nums->size() < n)
				nums->push_back(0);

			(*nums)[n - 1] = node->val;
			if (node->left != NULL)
				trav(node->left, n + 1);
			if (node->right != NULL)
				trav(node->right, n + 1);
		}
	}

private:
	int sum;
	vector<int> *nums;
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	Solution s;
	cout << s.sumNumbers(root) << endl;

	return 0;
}

