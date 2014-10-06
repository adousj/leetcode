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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		result = new vector<vector<int> >;
		if (root == NULL) return *result;
		trav(root, 0);
		return *result;
	}

	void trav(TreeNode *node, int n)
	{
		if (node == NULL) return;
		
		while (result->size() < n+1)
			result->push_back(vector<int>());

		if (n % 2 == 1)
			(*result)[n].insert((*result)[n].begin(), node->val);
		else
			(*result)[n].push_back(node->val);

		trav(node->left, n + 1);
		trav(node->right, n + 1);
	}
private:
	vector<vector<int> > *result;
};

int main()
{
	TreeNode *head;
	head = new TreeNode(3);
	head->left = new TreeNode(9);
	head->right = new TreeNode(20);
	head->right->left = new TreeNode(15);
	head->right->right = new TreeNode(7);

	Solution s;
	vector<vector<int> > result = s.zigzagLevelOrder(head);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

