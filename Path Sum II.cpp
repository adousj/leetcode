#include <iostream>
#include <vector>
#include <algorithm>

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
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		result = new vector<vector<int> >;
		if (root == NULL) return *result;
		nums = new vector<int>;
		trav(root, 0, sum);
		return *result;
	}

	void trav(TreeNode *node, int n, int sum)
	{
		if (node->left == NULL && node->right == NULL)
		{
			if (sum == node->val)
			{
				vector<int> vec = vector<int>(begin(*nums), begin(*nums) + n);
				vec.push_back(node->val);
				result->push_back(vec);
			}
		}
		else
		{
			while (n >= nums->size())
				nums->push_back(0);
			(*nums)[n] = node->val;
			if(node->left != NULL) trav(node->left, n + 1, sum - node->val);
			if(node->right != NULL) trav(node->right, n + 1, sum - node->val);
		}
	}

private:
	vector<int> *nums;
	vector<vector<int> > *result;
};

int main()
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	Solution s;
	auto result = s.pathSum(root, 22);
	result = s.pathSum(NULL, 1);

	for (auto r : result)
	{
		for (auto i : r)
			cout << i << " ";
		cout << endl;
	}


	return 0;
}

