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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (postorder.size() == 0 || postorder.size() != inorder.size()) return NULL;
		return trav(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());
	}

	TreeNode* trav(vector<int>::iterator a, vector<int>::iterator b, vector<int>::iterator c, vector<int>::iterator d)
	{
		if (a >= b) return NULL;

		TreeNode *head = new TreeNode(*(b-1));
		vector<int>::iterator e = find(c, d, *(b - 1));
		head->left = trav(a, e - c + a, c, e);
		head->right = trav(e - c + a, b-1, e + 1, d);
		return head;
	}
};

int main()
{
	int A[] = {4,2,5,3,1};
	int B[] = { 2,4,1,5,3};

	vector<int> post(A, A + sizeof(A) / sizeof(int));
	vector<int> in(B, B + sizeof(B) / sizeof(int));

	Solution s;
	TreeNode *node = s.buildTree(in,post);

	return 0;
}

